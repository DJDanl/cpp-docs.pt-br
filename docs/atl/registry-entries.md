---
title: "Entradas do registro | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Registro, entradas de serviços do ATL"
  - "Registro, IDs de aplicativo"
ms.assetid: 881989b7-61bb-459a-a13e-3bfcb33e184e
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Entradas do registro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

DCOM introduziu o conceito de IDs de aplicativo \(AppIDs\), qual grupo Opções de configuração para um ou mais objetos DCOM em um local centralizado no registro. Você pode especificar um AppID indicando seu valor no AppID chamado valor CLSID do objeto.  
  
 Por padrão, um serviço gerado ATL usa o CLSID que o GUID para seu AppID. Em `HKEY_CLASSES_ROOT\AppID`, você pode especificar entradas específicas do DCOM. Inicialmente, existem duas entradas:  
  
-   `LocalService`, com um valor igual ao nome do serviço. Se esse valor, ele é usado em vez do `LocalServer32` principais sob o CLSID.  
  
-   `ServiceParameters`, com um valor igual a `–Service`. Esse valor Especifica os parâmetros que serão passados para o serviço quando ele é iniciado. Observe que esses parâmetros são passados para o serviço `ServiceMain` funcione, não `WinMain`.  
  
 Qualquer serviço DCOM também precisa criar outra chave em `HKEY_CLASSES_ROOT\AppID`. Essa chave é igual ao nome do EXE e atua como uma referência cruzada, pois ele contém um valor de AppID apontando de volta para as entradas de AppID.  
  
## Consulte também  
 [Serviços](../atl/atl-services.md)