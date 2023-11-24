package main

import (
	"encoding/json"
	"fmt"
	"html/template"
	"os"
)

type Attribute struct {
	Name    string
	Default float32
}

type AttributeSet struct {
	ModuleName      string
	ClassName       string
	ParentClassName string
	TagPrefix       string
	Category        string
	CopyRight       string
	FileName        string
	HeaderIncludes  []string
	CppIncludes     []string
	Attributes      []Attribute
}

func (Set AttributeSet) GetOutputHeaderFilePath() string {
	return fmt.Sprintf("%s.h", Set.FileName)
}

func (Set AttributeSet) GetOutputCppFilePath() string {

	return fmt.Sprintf("%s.cpp", Set.FileName)
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
	attributeSet, err := ParseJSONFile("data.json")
	if err != nil {
		// 处理错误
	} else {
		// 使用 attributeSet 进行操作
	}

	{
		// 解析模板文件
		headerTmpl := "AttributeSet.h.tmpl"
		tmpl, err := template.ParseFiles(headerTmpl)
		if err != nil {
			fmt.Println("Failed to parse header template:", err)
			return
		}

		// 创建生成文件
		outputHeaderFile, err := os.Create(fmt.Sprintf("%s.h", attributeSet.ClassName))
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
		outputCppFile, err := os.Create(fmt.Sprintf("%s.cpp", attributeSet.ClassName))
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
