---
title: "Funções de importação e exportação de DLL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- DLLs [C++], importing
- dllimport attribute [C++], storage-class attribute
- DLL exports [C++]
- declaring functions, with dllexport and dllimport
- extended storage-class attributes
- dllexport attribute [C++], storage-class attribute
ms.assetid: 08d164b9-770a-4e14-afeb-c6f21d9e33e4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b79856a524cb9693d43d9929b22d6c63db5ba319
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dll-import-and-export-functions"></a>Funções de importação e exportação de DLL
**Seção específica da Microsoft**  
  
 As informações mais completas e atualizadas sobre este tópico podem ser encontradas em [dllexport, dllimport](../cpp/dllexport-dllimport.md).  
  
 Os modificadores da classe de armazenamento **dllimport** e `dllexport` são extensões específicas da Microsoft para a linguagem C. Esses modificadores definem explicitamente a interface da DLL para o cliente (o arquivo executável ou outra DLL). Declarar funções como `dllexport` elimina a necessidade de um arquivo de definição de módulo (.DEF). Você também pode usar os modificadores **dllimport** e `dllexport` com os dados e objetos.  
  
 Os modificadores de classe de armazenamento **dllimport** e `dllexport` devem ser usados com a palavra-chave de sintaxe de atributo estendida, `__declspec`, conforme mostrado neste exemplo:  
  
```  
#define DllImport   __declspec( dllimport )  
#define DllExport   __declspec( dllexport )  
  
DllExport void func();  
DllExport int i = 10;  
DllExport int j;  
DllExport int n;  
```  
  
 Para obter informações específicas sobre a sintaxe de modificadores de classe de armazenamento estendidos, consulte [Atributos de classe de armazenamento estendidos](../c-language/c-extended-storage-class-attributes.md).  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Definições de função C](../c-language/c-function-definitions.md)