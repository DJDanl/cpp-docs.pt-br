---
title: Entradas do registro (ATL) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- registry, ATL services entries
- registry, application IDs
ms.assetid: 881989b7-61bb-459a-a13e-3bfcb33e184e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: faef0ca0c1c9c4c2986a039b8b1a26517641acd0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="registry-entries"></a>Entradas do registro
DCOM introduziu o conceito de IDs de aplicativo (AppIDs), qual grupo de opções de configuração para um ou mais objetos DCOM em um local centralizado no registro. Você pode especificar um AppID indicando seu valor no AppID chamado valor CLSID do objeto.  
  
 Por padrão, um serviço gerado ATL usa sua CLSID como o GUID para seu AppID. Em `HKEY_CLASSES_ROOT\AppID`, você pode especificar entradas específicas de DCOM. Inicialmente, existem duas entradas:  
  
-   `LocalService`, com um valor igual ao nome do serviço. Se esse valor existe, ele é usado em vez do `LocalServer32` chave sob o CLSID.  
  
-   `ServiceParameters`, com um valor igual a `-Service`. Esse valor Especifica os parâmetros que serão passados para o serviço quando ele for iniciado. Observe que esses parâmetros são passados para o serviço `ServiceMain` função, não `WinMain`.  
  
 Qualquer serviço DCOM também precisa criar outra chave em `HKEY_CLASSES_ROOT\AppID`. Essa chave é igual ao nome do EXE e atua como uma referência cruzada, pois ela contém um valor de AppID apontando de volta para as entradas de AppID.  
  
## <a name="see-also"></a>Consulte também  
 [Serviços](../atl/atl-services.md)

