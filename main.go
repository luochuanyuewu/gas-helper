package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"text/template"
)

type Attribute struct {
	Name             string
	Default          float32
	MaxAttributeName string
	Comment          string
}

type AttributeSet struct {
	ModuleName            string
	ClassName             string
	UseAttributeHelper    bool
	ParentClassName       string
	TagPrefix             string
	Category              string
	CopyRight             string
	FileName              string
	HeaderOutputDirectory string
	CppOutputDirectory    string
	HeaderIncludes        []string
	CppIncludes           []string
	Attributes            []Attribute
}

func (Set AttributeSet) GetOutputHeaderFilePath() string {
	return fmt.Sprintf("%s/%s.h", Set.HeaderOutputDirectory, Set.FileName)
}

func (Set AttributeSet) GetOutputCppFilePath() string {

	return fmt.Sprintf("%s/%s.cpp", Set.CppOutputDirectory, Set.FileName)
}

func ParseJSONFile(filePath string) (AttributeSet, error) {
	var attributeSet AttributeSet

	// 读取 JSON 文件
	jsonBytes, err := os.ReadFile(filePath)
	if err != nil {
		return attributeSet, err
	}

	// 解析 JSON 数据
	err = json.Unmarshal(jsonBytes, &attributeSet)
	if err != nil {
		return attributeSet, err
	}

	if attributeSet.FileName == "" {
		attributeSet.FileName = attributeSet.ClassName
	}
	return attributeSet, nil
}

func main() {

	// 定义命令行参数
	filename := flag.String("file", "data.json", "JSON data file")

	// 解析命令行参数
	flag.Parse()

	attributeSet, err := ParseJSONFile(*filename)
	if err != nil {
		// 处理错误
		fmt.Println("Failed to open json file.")
		return
	} else {
		// 使用 attributeSet 进行操作
		{
			// 解析模板文件
			headerTmpl := "AttributeSet.h.tmpl"
			tmpl, err := template.ParseFiles(headerTmpl)
			if err != nil {
				fmt.Println("Failed to parse header template:", err)
				return
			}

			// 创建生成文件
			outputHeaderFile, err := os.Create(attributeSet.GetOutputHeaderFilePath())
			if err != nil {
				fmt.Println("Failed to create output file:", err)
				return
			}
			defer outputHeaderFile.Close()

			// 应用模板并写入文件
			err = tmpl.Execute(outputHeaderFile, attributeSet)
			if err != nil {
				fmt.Println("Failed to execute template:", err)
				return
			}
		}

		{
			// 解析模板文件
			cppTmpl := "AttributeSet.cpp.tmpl"
			tmpl, err := template.ParseFiles(cppTmpl)
			if err != nil {
				fmt.Println("Failed to parse cpp template:", err)
				return
			}

			// 创建生成文件
			outputCppFile, err := os.Create(attributeSet.GetOutputCppFilePath())
			if err != nil {
				fmt.Println("Failed to create output file:", err)
				return
			}
			defer outputCppFile.Close()

			// 应用模板并写入文件
			err = tmpl.Execute(outputCppFile, attributeSet)
			if err != nil {
				fmt.Println("Failed to execute template:", err)
				return
			}
		}

		fmt.Println("Output file generated successfully.")
	}

}
