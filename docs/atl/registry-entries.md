---
title: Entradas do registro (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- registry, ATL services entries
- registry, application IDs
ms.assetid: 881989b7-61bb-459a-a13e-3bfcb33e184e
ms.openlocfilehash: b61aae9ba9316dded1dcb11353e52eb2fffd49a2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50472872"
---
# <a name="registry-entries"></a>Entradas do registro

DCOM introduziu o conceito de IDs de aplicativo (AppIDs), qual grupo de opções de configuração para um ou mais objetos DCOM em um local centralizado no registro. Você pode especificar um AppID indicando seu valor no valor sob o CLSID do objeto nomeado AppID.

Por padrão, um serviço gerado pelo ATL usa sua CLSID que o GUID para seu AppID. Em `HKEY_CLASSES_ROOT\AppID`, você pode especificar entradas específicas de DCOM. Inicialmente, existem duas entradas:

- `LocalService`, com um valor igual ao nome do serviço. Se esse valor, ele é usado em vez do `LocalServer32` chave sob o CLSID.

- `ServiceParameters`, com um valor igual a `-Service`. Esse valor Especifica os parâmetros que serão passados para o serviço quando ele for iniciado. Observe que esses parâmetros são passados para o serviço `ServiceMain` função, não `WinMain`.

Também precisa de qualquer serviço do DCOM criar outra chave sob `HKEY_CLASSES_ROOT\AppID`. Essa chave é igual ao nome do EXE e atua como uma referência cruzada, pois ela contém um valor de AppID apontando de volta para as entradas de AppID.

## <a name="see-also"></a>Consulte também

[Serviços](../atl/atl-services.md)

