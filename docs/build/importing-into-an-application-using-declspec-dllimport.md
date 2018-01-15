---
title: Importando para um aplicativo usando __declspec(dllimport) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- __declspec
- dllimport
dev_langs: C++
helpviewer_keywords:
- __declspec(dllimport) keyword [C++]
- importing DLLs [C++], __declspec(dllimport)
ms.assetid: edb4da4e-f83a-44cf-a668-9239d49dbe42
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9766c6088e3f99711b936b10db0443da49b52c6c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="importing-into-an-application-using-declspecdllimport"></a>Importando para um aplicativo usando __declspec(dllimport)
Um programa que usa os símbolos públicos definidos por uma DLL deve importá-los. Quando você cria arquivos de cabeçalho para aplicativos que usam suas DLLs para criar, usar **__declspec(dllimport)** em declarações dos símbolos públicos. A palavra-chave **__declspec(dllimport)** funciona se você exportar arquivos. def ou com o **dllexport** palavra-chave.  
  
 Para tornar seu código mais legível, definir uma macro para **__declspec(dllimport)** e, em seguida, use a macro para declarar cada símbolo importado:  
  
```  
#define DllImport   __declspec( dllimport )  
  
DllImport int  j;  
DllImport void func();  
```  
  
 Usando **__declspec(dllimport)** é opcional em declarações de função, mas o compilador gera o código mais eficiente se você usar a palavra-chave. No entanto, você deve usar **__declspec(dllimport)** para o executável de importação acessar a DLL símbolos de dados públicos e objetos. Observe que os usuários da sua DLL ainda precisam vincular a uma biblioteca de importação.  
  
 Você pode usar o mesmo arquivo de cabeçalho para a DLL e o aplicativo cliente. Para fazer isso, use um símbolo do pré-processador especial que indica se você está criando a DLL ou compilar o aplicativo cliente. Por exemplo:  
  
```  
#ifdef _EXPORTING  
   #define CLASS_DECLSPEC    __declspec(dllexport)  
#else  
   #define CLASS_DECLSPEC    __declspec(dllimport)  
#endif  
  
class CLASS_DECLSPEC CExampleA : public CObject  
{ ... class definition ... };  
```  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Inicializar uma DLL](../build/run-time-library-behavior.md#initializing-a-dll)  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Importando e exportando funções embutidas](../build/importing-and-exporting-inline-functions.md)  
  
-   [Importações mútuas](../build/mutual-imports.md)  
  
## <a name="see-also"></a>Consulte também  
 [Importando para um aplicativo](../build/importing-into-an-application.md)