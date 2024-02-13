# Introduction

A simple command-line tool that helps you quickly generate AttributeSet for Unreal Engine GameplayAbility system based
on JSON configuration.

# Requirements

1. You need have a UE 5.1(and above) C++ project.
2. Add module "GameplayAbilities" and "GameplayTags" to "YourModule.build.cs"  

# Usage

Add new or modify existing .json files to custom to your needs.

1. Change "ModuleName": "ACTIONRPG" to your module name.
2. Change "ParentClassName": "AttributeSet".
3. Change HeaderOutputDirectory and CppOutputDirectory.
4. Run gen_modular.sh or gen_monolith.sh to generate code.

See [ThisPage](https://www.yuewu.dev/gas-helper) for more details.

