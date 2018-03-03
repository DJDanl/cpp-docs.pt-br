---
title: "-Zc: strictStrings (desativar conversão de tipo literal de cadeia de caracteres) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /Zc:strictStrings
- strictStrings
dev_langs:
- C++
helpviewer_keywords:
- /Zc:strictStrings
- -Zc compiler options (C++)
- strictStrings
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: b7eb3f3b-82c1-48a2-8e63-66bad7397b46
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f316c5fc9209f968219d770a15e6576880b69954
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="zcstrictstrings-disable-string-literal-type-conversion"></a>/Zc:strictStrings (Desativar conversão de tipo literal de cadeia de caracteres)
Quando especificado, o compilador exige conformidade rígida com qualificação de `const` para ponteiros inicializados com literais da cadeia de caracteres.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Zc:strictStrings[-]  
```  
  
## <a name="remarks"></a>Comentários  
 Se **/ZC: strictstrings** for especificado, o compilador aplica o C++ padrão `const` qualificações para literais de cadeia de caracteres, como o tipo ' array de `const char`' ou ' matriz de `const wchar_t`', dependendo da declaração. Os literais da cadeia de caracteres são imutáveis, e uma tentativa de modificar o conteúdo de um resulta em um erro de violação de acesso em tempo de execução. Você deve declarar um ponteiro da cadeia de caracteres como `const` para inicializá-lo usando um literal da cadeia de caracteres ou usar um `const_cast` explícito para inicializar um ponteiro não `const`. Por padrão, ou se **/Zc:strictStrings-** for especificado, o compilador não impõe o C++ padrão `const` qualificações inicializadas usando literais de cadeia de caracteres de ponteiros de cadeia de caracteres.  
  
 Use o **/ZC: strictstrings** opção para impedir que a compilação de código incorreto. Este exemplo mostra como um erro de declaração simples leva a uma falha em tempo de execução:  
  
```cpp  
// strictStrings_off.cpp  
// compile by using: cl /W4 strictStrings_off.cpp  
int main() {  
   wchar_t* str = L"hello";  
   str[2] = L'a'; // run-time error: access violation  
}  
```  
  
 Quando **/ZC: strictstrings** está habilitado, o mesmo código relata um erro na declaração de `str`.  
  
```cpp  
// strictStrings_on.cpp  
// compile by using: cl /Zc:strictStrings /W4 strictStrings_on.cpp  
int main() {  
   wchar_t* str = L"hello"; // error: Conversion from string literal   
   // loses const qualifier  
   str[2] = L'a';   
}  
```  
  
 Se você usar `auto` para declarar um ponteiro da cadeia de caracteres, o compilador criará a declaração do tipo de ponteiro `const` correta para você. Uma tentativa de modificar o conteúdo de um ponteiro `const` é relatada pelo compilador como um erro.  
  
> [!NOTE]
>  A biblioteca padrão C++ em [!INCLUDE[cpp_dev12_long](../../build/reference/includes/cpp_dev12_long_md.md)] não oferece suporte a **/ZC: strictstrings** compilações de opção de compilador na depuração. Se você vir várias [C2665](../../error-messages/compiler-errors-2/compiler-error-c2665.md) erros na criação de saída, isso pode ser a causa.  
  
 Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Modificar o **opções adicionais** propriedade incluir `/Zc:strictStrings` e, em seguida, escolha **Okey**.  
  
## <a name="see-also"></a>Consulte também  
 [/ZC (conformidade)](../../build/reference/zc-conformance.md)