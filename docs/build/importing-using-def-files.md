---
title: Importando usando arquivos DEF | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- importing DLLs [C++], DEF files
- def files [C++], importing with
- .def files [C++], importing with
- dllimport attribute [C++], DEF files
- DLLs [C++], DEF files
ms.assetid: aefdbf50-f603-488a-b0d7-ed737bae311d
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ee213f1aa381415444288dbab4473cae6f5fc7b9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="importing-using-def-files"></a>Importando usando arquivos DEF
Se você optar por usar **__declspec(dllimport)** junto com um arquivo. def, você deve alterar o arquivo. def para usar dados no lugar de constante para reduzir a probabilidade de que a codificação incorreta fará com que um problema:  
  
```  
// project.def  
LIBRARY project  
EXPORTS  
   ulDataInDll   DATA  
```  
  
 A tabela a seguir mostra por que.  
  
|Palavra-chave|Emite na biblioteca de importação|Exportações|  
|-------------|---------------------------------|-------------|  
|`CONSTANT`|`_imp_ulDataInDll`, `_ulDataInDll`|`_ulDataInDll`|  
|`DATA`|`_imp_ulDataInDll`|`_ulDataInDll`|  
  
 Usando **__declspec(dllimport)** e constante lista ambos o `imp` versão e o nome não decorado na DLL. lib Importar biblioteca que é criada para permitir que a vinculação explícita. Usando **__declspec(dllimport)** e listas de dados apenas o `imp` versão do nome.  
  
 Se você usar a constante, uma das construções de código a seguir pode ser usada para acessar `ulDataInDll`:  
  
```  
__declspec(dllimport) ULONG ulDataInDll; /*prototype*/  
if (ulDataInDll == 0L)   /*sample code fragment*/  
```  
  
 -ou-  
  
```  
ULONG *ulDataInDll;      /*prototype*/  
if (*ulDataInDll == 0L)  /*sample code fragment*/  
```  
  
 No entanto, se você usar dados em seu arquivo. def, apenas o código compilado com a seguinte definição pode acessar a variável `ulDataInDll`:  
  
```  
__declspec(dllimport) ULONG ulDataInDll;  
  
if (ulDataInDll == 0L)   /*sample code fragment*/  
```  
  
 Usando a constante é mais arriscado, porque se você se esqueça de usar o nível extra de indireção, você pode acessar potencialmente ponteiro da tabela de endereço de importação para a variável, não a variável em si. Esse tipo de problema geralmente pode manifestar como uma violação de acesso porque a tabela de endereço de importação é feita no momento somente leitura, o compilador e vinculador.  
  
 O vinculador atual do Visual C++ emite um aviso se ele vê constante no arquivo. def para a conta para este caso. O motivo real só usar constante é se não for possível recompilar algum arquivo de objeto em que o arquivo de cabeçalho não lista **__declspec(dllimport)** no protótipo.  
  
## <a name="see-also"></a>Consulte também  
 [Importando para um aplicativo](../build/importing-into-an-application.md)
