---
title: Especificadores de substituição (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- override specifiers, Visual C++
- override specifiers
ms.assetid: 155bbf6f-4722-4654-afb1-9cb52af799fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f84379e57dc5730227726d28c6947d0274b615c5
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39603908"
---
# <a name="override-specifiers--c-component-extensions"></a>Especificadores de Substituição (Extensões de Componentes C++)
*Especificadores de substituição* modificar herdados como tipos e membros de tipos herdados se comportam em tipos derivados.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
### <a name="remarks"></a>Comentários  
  
 Para obter mais informações sobre especificadores de substituição, consulte:  
  
-   [abstract](../windows/abstract-cpp-component-extensions.md)  
  
-   [novo (novo slot em vtable)](../windows/new-new-slot-in-vtable-cpp-component-extensions.md)  
  
-   [override](../windows/override-cpp-component-extensions.md)  
  
-   [sealed](../windows/sealed-cpp-component-extensions.md)  
  
-   [Especificadores de substituição e compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md)  
  
 **abstrato** e **lacrado** também são válidos em declarações de tipo, onde não atuam como especificadores de substituição.  
  
 Para obter informações sobre como substituir explicitamente funções de classe base, consulte [substituições explícitas](../windows/explicit-overrides-cpp-component-extensions.md).  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 (Não há nenhum comentário sobre este recurso de linguagem que se aplicam a apenas o tempo de execução do Windows.)  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: `/ZW`  
  
## <a name="common-language-runtime"></a>Common Language Runtime  
 (Não há nenhum comentário sobre este recurso de linguagem que se aplicam a apenas o common language runtime.)  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: `/clr`  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)