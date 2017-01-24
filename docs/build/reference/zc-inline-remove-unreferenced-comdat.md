---
title: "/Zc:inline (remover COMDAT n&#227;o referenciado) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/Zc:inline"
  - "VC.Project.VCCLCompilerTool.RemoveUnreferencedCodeData"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "opç;ões de compilador /Zc (C++)"
  - "/Zc:inline"
  - "opç;ões de compilador Zc (C++)"
  - "opç;ões de compilador -Zc (C++)"
ms.assetid: a4c94224-1d73-4bea-a9d5-4fa73dc924df
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Zc:inline (remover COMDAT n&#227;o referenciado)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Remove funções não referenciadas ou dados que sejam COMDATs ou que tenham apenas vínculo interno.  Quando **\/Zc:inline** é especificado, o compilador exige que as unidades de tradução que usam dados ou funções embutidos também incluam as definições dos dados ou das funções.  
  
## Sintaxe  
  
```  
/Zc:inline[-]  
```  
  
## Comentários  
 Quando **\/Zc:inline** é especificado, o compilador não emite informações do símbolo para funções ou dados COMDAT não referenciados, ou para funções ou dados que tenham apenas vínculo interno.  Por padrão, essa opção permanece desativada \(**\/Zc:inline\-**\).  Essa otimização simplifica parte do trabalho realizado pelo vinculador em compilações de versão ou quando a opção do vinculador [\/OPT:REF](../../build/reference/opt-optimizations.md) é especificada.  Ao realizar essa otimização, o compilador pode reduzir significativamente o tamanho do arquivo .obj e aumentar as velocidades do vinculador.  Essa opção do compilador não permanece habilitada quando as otimizações estão desabilitadas \([\/Od](../../build/reference/od-disable-debug.md)\) ou quando [\/GL \(otimização de todo o programa\)](../../build/reference/gl-whole-program-optimization.md) é especificado.  
  
 Caso **\/Zc:inline** seja especificado, o compilador impõe o requisito C\+\+11 de que, se forem usadas, todas as funções declaradas `inline` deverão ter uma definição disponível na mesma unidade de tradução.  Quando a opção não é especificada, o [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] permite o código em não conformidade que invoca as funções declaradas `inline`, mesmo que não haja uma definição visível.  Para obter mais informações, consulte o padrão do C\+\+11, nas seções 3.2 e 7.1.2.  Essa opção do compilador foi introduzida no Visual Studio 2013 Atualização 2.  
  
 Para usar a opção **\/Zc:inline**, atualize o código não compatível.  Este exemplo mostra como o uso não compatível de uma declaração de função embutida sem uma definição ainda é compilada e vinculada quando a opção **\/Zc:inline\-** é usada:  
  
```cpp  
// example.h  
// Compile by using: cl /W4 /EHsc /O2 zcinline.cpp example.cpp  
#pragma once  
  
class Example {  
public:  
   inline void inline_call(); // declared but not defined inline  
   void normal_call();  
   Example() {};  
};  
```  
  
```cpp  
// example.cpp  
// Compile by using: cl /W4 /EHsc /O2 zcinline.cpp example.cpp  
#include <stdio.h>  
#include "example.h"  
  
void Example::inline_call() {  
   printf("inline_call was called.\n");   
}  
  
void Example::normal_call() {  
   printf("normal_call was called.\n");   
   inline_call(); // with /Zc:inline-, inline_call forced into .obj file  
}  
```  
  
```cpp  
// zcinline.cpp  
// Compile by using: cl /W4 /EHsc /O2 zcinline.cpp example.cpp  
#include "example.h"  
  
void main() {  
   Example example;  
   example.inline_call(); // normal call when definition unavailable  
}  
```  
  
 Quando **\/Zc:inline** é habilitado, o mesmo código causa um erro [LNK2019](../Topic/Linker%20Tools%20Error%20LNK2019.md), porque o compilador não emite um corpo de código não embutido para `Example::inline_call` em example.obj.  Isso faz a chamada não embutida em `main` mencionar um símbolo externo indefinido.  
  
 Para resolver esse erro, é possível remover a palavra\-chave `inline` da declaração de `Example::inline_call`, mover a definição de `Example::inline_call` para o arquivo de cabeçalho ou mover a implementação de `Example` para main.cpp.  O próximo exemplo move a definição para o arquivo de cabeçalho, onde ele permanece visível para qualquer chamador com o cabeçalho.  
  
```cpp  
// example2.h  
// Compile by using: cl /W4 /EHsc /O2 zcinline2.cpp example2.cpp  
#pragma once  
#include <stdio.h>  
  
class Example2 {  
public:  
   inline void inline_call() {  
      printf("inline_call was called.\n");   
   }  
   void normal_call();  
   Example2() {};  
};  
```  
  
```cpp  
// example2.cpp  
// Compile by using: cl /W4 /EHsc /O2 zcinline2.cpp example2.cpp  
#include "example2.h"  
  
void Example2::normal_call() {  
   printf("normal_call was called.\n");   
   inline_call();   
}  
```  
  
```cpp  
// zcinline2.cpp  
// Compile by using: cl /W4 /EHsc /O2 zcinline2.cpp example2.cpp  
#include "example2.h"  
  
void main() {  
   Example2 example2;  
   example2.inline_call(); // normal call when definition unavailable  
}  
```  
  
 Para obter mais informações sobre problemas de conformidade no Visual C\+\+, consulte [Comportamento não padrão](../Topic/Nonstandard%20Behavior.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades de **Linha de Comando**.  
  
4.  Modifique a propriedade **Opções Adicionais** para incluir `/Zc:inline` e escolha **OK**.  
  
## Consulte também  
 [\/Zc \(conformidade\)](../../build/reference/zc-conformance.md)