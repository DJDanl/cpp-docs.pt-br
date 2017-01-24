---
title: "Chamando fun&#231;&#245;es DLL a partir de aplicativos Visual Basic | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __stdcall [C++]"
  - "chamando funções DLL a partir de aplicativos VB [C++]"
  - "Funções DLL [C++]"
  - "Funções DLL [C++], Chamando "
  - "DLLs [C++], Chamando "
  - "chamadas de função [C++], funções DLL"
  - "funções [C++], chamando funções DLL a partir do Visual Basic"
ms.assetid: 282f7fbf-a0f2-4b9f-b277-1982710be56c
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Chamando fun&#231;&#245;es DLL a partir de aplicativos Visual Basic
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para aplicativos Visual Basic \(ou aplicativos em outros idiomas como Pascal ou Fortran\) chamarem funções no C\/C\+\+ DLL, as funções devem ser exportadas usando a convenção correta de chamada sem nenhuma decoração de nome feita pelo compilador.  
  
 `__stdcall` cria a convenção correta de chamada para a função \(a função chamada limpa a pilha e os parâmetros são passados da direita para a esquerda\), mas adorna o nome da função de maneira diferente.  Assim, quando **\_\_declspec\(dllexport\)** é usado em uma função exportada em uma DLL, o nome decorado é exportado.  
  
 A decoração de nome `__stdcall` prefixa o nome do símbolo com um sublinhado \(\_\) e acrescenta o símbolo com um caractere da arroba \(@\) seguido pelo número de bytes na lista de argumentos \(o espaço de pilha necessário\).  Como resultado, a função quando declarada como:  
  
```  
int __stdcall func (int a, double b)  
```  
  
 é decorado como:  
  
```  
_func@12  
```  
  
 A convenção de chamada do C \(`__cdecl`\) decora o nome como `_func`.  
  
 Para obter o nome decorado, use [\/MAP](../build/reference/map-generate-mapfile.md).  O uso de **\_\_declspec\(dllexport\)** faz o seguinte:  
  
-   Se a função for exportada com a convenção de chamada C \(**\_cdecl**\), ela tira o sublinhado \(\_\) principal quando o nome é exportado.  
  
-   Se a função que está sendo exportada não usa a convenção de chamada C \(por exemplo, `__stdcall`\), ela exporta o nome decorado.  
  
 Como não há nenhuma maneira de substituir onde a limpeza de pilha ocorre, você deve usar `__stdcall`.  Para os nomes não decorados com `__stdcall`, você deve especificá\-los usando aliases na seção de EXPORTAÇÕES do arquivo .def.  Isso será mostrado a seguir para a seguinte declaração de função:  
  
```  
int  __stdcall MyFunc (int a, double b);  
void __stdcall InitCode (void);  
```  
  
 No arquivo .DEF:  
  
```  
EXPORTS  
   MYFUNC=_MyFunc@12  
   INITCODE=_InitCode@0  
```  
  
 Para que as DLLs sejam chamadas pelos programas escritos no Visual Basic, a técnica do alias exibida neste tópico é necessária no arquivo .def.  Se o alias for feito no programa Visual Basic, o uso de serrilhado no arquivo .def não será necessário.  Pode ser feito no programa Visual Basic, adicionando uma cláusula alias para a declaração [Declarar](../Topic/Declare%20Statement.md).  
  
## Que você deseja saber mais?  
  
-   [Exportação de uma DLL](../build/exporting-from-a-dll.md)  
  
-   [Exportação de uma DLL usando arquivos .def](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportação de uma DLL usando \_\_declspec\(dllexport\)](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportação de funções de C\+\+ para uso em executáveis de linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)  
  
-   [Determinando o método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Nomes decorados](../Topic/Decorated%20Names.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)