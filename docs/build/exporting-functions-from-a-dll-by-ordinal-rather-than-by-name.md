---
title: "Exportando funções a partir de uma DLL por Ordinal em vez de nome | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: NONAME
dev_langs: C++
helpviewer_keywords:
- exporting functions [C++], ordinal values
- ordinal exports [C++]
- exporting DLLs [C++], ordinal values
- NONAME attribute
ms.assetid: 679719fd-d965-4df3-9f7a-7d86ad831702
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 17b49cc54336f596d6815a2ebe53e60ed2dd51e8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exporting-functions-from-a-dll-by-ordinal-rather-than-by-name"></a>Exportando funções a partir de uma DLL por ordinal e não por nome
A maneira mais simples para exportar funções de sua DLL é exportá-los por nome. Este é o que acontece quando você usar **dllexport**, por exemplo. Mas, em vez disso, você pode exportar funções por ordinal. Com essa técnica, você deve usar um arquivo. def, em vez de **dllexport**. Para especificar o valor ordinal da função, acrescente seu ordinal para o nome da função no arquivo. def. Para obter informações sobre como especificar ordinais, consulte [exportando a partir de uma DLL usando arquivos. def](../build/exporting-from-a-dll-using-def-files.md).  
  
> [!TIP]
>  Se você deseja otimizar o tamanho do arquivo da DLL, use o **NONAME** atributo em cada função exportada. Com o **NONAME** atributo, os ordinais são armazenados na DLL exporta a tabela em vez de nomes de função. Isso pode ser uma economia considerável se você estiver exportando várias funções.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Usar um arquivo. def, portanto, pode exportar por ordinal](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Use dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
## <a name="see-also"></a>Consulte também  
 [Exportando de uma DLL](../build/exporting-from-a-dll.md)