---
title: GetProcAddress | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- GetProcAddress
dev_langs:
- C++
helpviewer_keywords:
- DLLs [C++], GetProcAddress
- ordinal exports [C++]
- GetProcAddress method
ms.assetid: 48d14ae0-47ea-4c5d-96b1-2c158f1a26af
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2bc32c5f6b6ae4ee80c69dff028f05d2b334d920
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="getprocaddress"></a>GetProcAddress
Vinculando explicitamente para uma chamada DLL de processos [GetProcAddress](http://msdn.microsoft.com/library/windows/desktop/ms683212) para obter o endereço de uma função exportada na DLL. Você pode usar o ponteiro de função retornado para chamar a função DLL. **GetProcAddress** usa como parâmetros a alça do módulo DLL (retornado pelo **LoadLibrary**, `AfxLoadLibrary`, ou **GetModuleHandle**) e usa o nome da função você deseja chamada ou exportação de função ordinal.  
  
 Como você está chamando a função DLL por meio de um ponteiro e não há nenhuma verificação de tipo de tempo de compilação, certifique-se de que os parâmetros para a função estão corretos para que você não overstep a memória alocada na pilha e causar uma violação de acesso. Uma maneira para ajudar a fornecer a segurança de tipo é examinar os protótipos de função das funções exportadas e criar definições de tipo correspondentes para os ponteiros de função. Por exemplo:  
  
```  
typedef UINT (CALLBACK* LPFNDLLFUNC1)(DWORD,UINT);  
...  
  
HINSTANCE hDLL;               // Handle to DLL  
LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer  
DWORD dwParam1;  
UINT  uParam2, uReturnVal;  
  
hDLL = LoadLibrary("MyDLL");  
if (hDLL != NULL)  
{  
   lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL,  
                                           "DLLFunc1");  
   if (!lpfnDllFunc1)  
   {  
      // handle the error  
      FreeLibrary(hDLL);  
      return SOME_ERROR_CODE;  
   }  
   else  
   {  
      // call the function  
      uReturnVal = lpfnDllFunc1(dwParam1, uParam2);  
   }  
}  
```  
  
 Como especificar a função que você deseja ao chamar **GetProcAddress** depende de como a DLL foi compilada.  
  
 Você pode obter o ordinal de exportação somente se a DLL que você está vinculando é compilada com um arquivo de definição (. def) do módulo e os ordinais são listados com as funções no **exportações** seção do arquivo. def da DLL. Chamando **GetProcAddress** com uma exportação ordinal, em vez do nome de função é ligeiramente mais rápida se a DLL tem muitas funções exportadas porque os ordinais de exportação servem como índices, a DLL de tabela de exportação. Com um ordinal de exportação, **GetProcAddress** pode localizar a função diretamente, em vez de comparar o nome especificado para os nomes de função na tabela de exportação da DLL. No entanto, você deve chamar **GetProcAddress** com um ordinal de exportação somente se você tem controle sobre a atribuição de ordinais para as funções exportadas no arquivo. def.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Como vincular implicitamente para uma DLL](../build/linking-an-executable-to-a-dll.md#linking-implicitly)  
  
-   [Determinar qual método de associação usar](../build/linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [LoadLibrary e AfxLoadLibrary](../build/loadlibrary-and-afxloadlibrary.md)  
  
-   [FreeLibrary](http://msdn.microsoft.com/library/windows/desktop/ms683152)  
  
-   [Exportando de uma DLL usando arquivos DEF](../build/exporting-from-a-dll-using-def-files.md)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)