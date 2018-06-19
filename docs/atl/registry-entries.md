---
title: Entradas do registro (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- registry, ATL services entries
- registry, application IDs
ms.assetid: 881989b7-61bb-459a-a13e-3bfcb33e184e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ac8e202fc2fc3d58e2d57a9fbfa15264d9fd310e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32359723"
---
# <a name="registry-entries"></a>Entradas do registro
DCOM introduziu o conceito de IDs de aplicativo (AppIDs), qual grupo de opções de configuração para um ou mais objetos DCOM em um local centralizado no registro. Você pode especificar um AppID indicando seu valor no AppID chamado valor CLSID do objeto.  
  
 Por padrão, um serviço gerado ATL usa sua CLSID como o GUID para seu AppID. Em `HKEY_CLASSES_ROOT\AppID`, você pode especificar entradas específicas de DCOM. Inicialmente, existem duas entradas:  
  
-   `LocalService`, com um valor igual ao nome do serviço. Se esse valor existe, ele é usado em vez do `LocalServer32` chave sob o CLSID.  
  
-   `ServiceParameters`, com um valor igual a `-Service`. Esse valor Especifica os parâmetros que serão passados para o serviço quando ele for iniciado. Observe que esses parâmetros são passados para o serviço `ServiceMain` função, não `WinMain`.  
  
 Qualquer serviço DCOM também precisa criar outra chave em `HKEY_CLASSES_ROOT\AppID`. Essa chave é igual ao nome do EXE e atua como uma referência cruzada, pois ela contém um valor de AppID apontando de volta para as entradas de AppID.  
  
## <a name="see-also"></a>Consulte também  
 [Serviços](../atl/atl-services.md)

