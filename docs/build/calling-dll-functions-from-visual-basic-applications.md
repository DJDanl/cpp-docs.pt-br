---
title: "Chamando funções DLL a partir de aplicativos do Visual Basic | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- functions [C++], calling DLL functions from Visual Basic
- DLL functions [C++]
- function calls [C++], DLL functions
- DLLs [C++], calling
- calling DLL functions from VB applications [C++]
- __stdcall keyword [C++]
- DLL functions [C++], calling
ms.assetid: 282f7fbf-a0f2-4b9f-b277-1982710be56c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ed99b0ebe41a8f1bc9684638fa74e18556dd51f5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="calling-dll-functions-from-visual-basic-applications"></a>Chamando funções DLL a partir de aplicativos Visual Basic
Para aplicativos do Visual Basic (ou aplicativos em outras linguagens, como Pascal ou Fortran) chamar funções em uma DLL do C/C++, as funções devem ser exportadas usando a convenção de chamada correta sem qualquer decoração de nome feita pelo compilador.  
  
 `__stdcall`cria a convenção de chamada correta para a função (a função chamada limpa a pilha e os parâmetros são passados da direita para esquerda), mas decora o nome da função de forma diferente. Portanto, quando **dllexport** é usado em uma função exportada em uma DLL, o nome decorado é exportado.  
  
 O `__stdcall` decoração do nome define o nome do símbolo com um sublinhado (_) e anexa o símbolo com um sinal de arroba (@) caractere seguido pelo número de bytes na lista de argumentos (o espaço de pilha necessário). Como resultado, a função quando declarado como:  
  
```  
int __stdcall func (int a, double b)  
```  
  
 é decorado como:  
  
```  
_func@12  
```  
  
 A convenção de chamada C (`__cdecl`) decora o nome como `_func`.  
  
 Para obter o nome decorado, use [/MAPEAR](../build/reference/map-generate-mapfile.md). O uso de **dllexport** faz o seguinte:  
  
-   Se a função será exportada com a convenção de chamada C (**cdecl**), ele extrai o sublinhado (_) à esquerda quando o nome é exportado.  
  
-   Se a função que estão sendo exportada não usa a convenção de chamada C (por exemplo, `__stdcall`), que exporta o nome decorado.  
  
 Como não há nenhuma maneira de substituir onde ocorre a limpeza da pilha, você deve usar `__stdcall`. Para undecorate nomes com `__stdcall`, você deve especificá-los usando aliases na seção do arquivo. def EXPORTS. Isso é mostrado a seguir para a declaração de função a seguir:  
  
```  
int  __stdcall MyFunc (int a, double b);  
void __stdcall InitCode (void);  
```  
  
 No. Arquivo de definição:  
  
```  
EXPORTS  
   MYFUNC=_MyFunc@12  
   INITCODE=_InitCode@0  
```  
  
 Para DLLs seja chamado por programas escritos em Visual Basic, a técnica de alias mostrada neste tópico é necessária no arquivo. def. Se o alias é feito no programa Visual Basic, o uso de alias no arquivo. def não é necessário. Isso pode ser feito no programa Visual Basic, adicionando uma cláusula de alias para o [Declare](/dotnet/visual-basic/language-reference/statements/declare-statement) instrução.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Exportando de uma DLL](../build/exporting-from-a-dll.md)  
  
-   [Exportando a partir de uma DLL usando. Arquivos DEF](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportando a partir de uma DLL usando dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportando funções C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)  
  
-   [Determinando qual método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Nomes decorados](../build/reference/decorated-names.md)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)