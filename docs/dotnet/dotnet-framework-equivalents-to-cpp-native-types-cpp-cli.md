---
title: Equivalentes do .NET framework aos tipos nativos do C++ (C + + CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- .NET Framework [C++], C++ equivalents
ms.assetid: 7f116a9a-26cd-46db-9877-a63ffdc88723
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: af9038015cd8211bcd66c08b5377d43cf7639668
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33110932"
---
# <a name="net-framework-equivalents-to-c-native-types-ccli"></a>Equivalentes do .NET Framework aos tipos nativos do C++ (C++/CLI)
A tabela a seguir mostra as palavras-chave para tipos internos do Visual C++, que são aliases de tipos predefinidos no **sistema** namespace.  
  
|Tipo de Visual C++|Tipo do .NET Framework|  
|-----------------------|-------------------------|  
|**bool**|**System.Boolean**|  
|**assinado char** (consulte [/J](../build/reference/j-default-char-type-is-unsigned.md) para obter mais informações)|**System.SByte**|  
|**unsigned char**|**System.Byte**|  
|**wchar_t**|**System.Char**|  
|**duplo** e **longo duplo**|**System.Double**|  
|**float**|**System.Single**|  
|**int**, **assinado int**, **longo**, e **assinado longa**|**System.Int32**|  
|**int não assinado** e **não assinado longa**|**System.UInt32**|  
|**Int64** e **assinado Int64**|**System.Int64**|  
|**unsigned __int64**|**System.UInt64**|  
|**curto** e **assinado curta**|**System.Int16**|  
|**unsigned short**|**System.UInt16**|  
|**void**|**System. void**|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos gerenciados (C++/CLI)](../dotnet/managed-types-cpp-cli.md)