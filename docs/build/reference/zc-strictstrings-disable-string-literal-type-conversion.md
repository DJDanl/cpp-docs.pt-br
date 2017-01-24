---
title: "/Zc:strictStrings (Desativar convers&#227;o de tipo literal de cadeia de caracteres) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/Zc:strictStrings"
  - "strictStrings"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "opções de compilador /Zc (C++)"
  - "/Zc:strictStrings"
  - "strictStrings"
  - "opções de compilador Zc (C++)"
  - "opções de compilador -Zc (C++)"
ms.assetid: b7eb3f3b-82c1-48a2-8e63-66bad7397b46
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Zc:strictStrings (Desativar convers&#227;o de tipo literal de cadeia de caracteres)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando especificado, o compilador exige conformidade rígida com qualificação de `const` para ponteiros inicializados com literais da cadeia de caracteres.  
  
## Sintaxe  
  
```  
/Zc:strictStrings[-]  
```  
  
## Comentários  
 Se **\/Zc:strictStrings** for especificado, o compilador forçará as qualificações de `const` em C\+\+ para literais da cadeia de caracteres, como o tipo 'matriz de `const` `char`' ou 'matriz de `const` `wchar_t`', dependendo da declaração.  Os literais da cadeia de caracteres são imutáveis, e uma tentativa de modificar o conteúdo de um resulta em um erro de violação de acesso em tempo de execução.  Você deve declarar um ponteiro da cadeia de caracteres como `const` para inicializá\-lo usando um literal da cadeia de caracteres ou usar um `const_cast` explícito para inicializar um ponteiro não `const`.  Por padrão, ou se **\/Zc:strictStrings\-** for especificado, o compilador não vai impor as qualificações de `const` em C\+\+ padrão para ponteiros da cadeia de caracteres inicializados com literais da cadeia de caracteres.  
  
 Use a opção **\/Zc:strictStrings** para evitar a compilação de código incorreto.  Este exemplo mostra como um erro de declaração simples leva a uma falha em tempo de execução:  
  
```cpp  
// strictStrings_off.cpp  
// compile by using: cl /W4 strictStrings_off.cpp  
int main() {  
   wchar_t* str = L"hello";  
   str[2] = L'a'; // run-time error: access violation  
}  
```  
  
 Quando **\/Zc:strictStrings** está habilitado, o mesmo código relata um erro na declaração de `str`.  
  
```cpp  
// strictStrings_on.cpp  
// compile by using: cl /Zc:strictStrings /W4 strictStrings_on.cpp  
int main() {  
   wchar_t* str = L"hello"; // error: Conversion from string literal   
   // loses const qualifier  
   str[2] = L'a';   
}  
```  
  
 Se você usar `auto` para declarar um ponteiro da cadeia de caracteres, o compilador criará a declaração do tipo de ponteiro `const` correta para você.  Uma tentativa de modificar o conteúdo de um ponteiro `const` é relatada pelo compilador como um erro.  
  
> [!NOTE]
>  A Biblioteca Padrão C\+\+ no [!INCLUDE[cpp_dev12_long](../../build/reference/includes/cpp_dev12_long_md.md)] não oferece suporte à opção de compilador **\/Zc:strictStrings** em compilações de depuração.  Se você vir diversos erros [C2665](../../error-messages/compiler-errors-2/compiler-error-c2665.md) na saída da compilação, essa poderá ser a causa.  
  
 Para obter mais informações sobre problemas de conformidade no Visual C\+\+, consulte [Comportamento não padrão](../Topic/Nonstandard%20Behavior.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades de **Linha de Comando**.  
  
4.  Modifique a propriedade **Opções Adicionais** para incluir `/Zc:strictStrings` e escolha **OK**.  
  
## Consulte também  
 [\/Zc \(conformidade\)](../../build/reference/zc-conformance.md)