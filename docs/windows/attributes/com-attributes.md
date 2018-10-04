---
title: Atributos COM | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++/CLI], reference topics
- attributes [COM]
- COM, attributes
ms.assetid: 52a5dd70-e8be-4bba-afd6-daf90fe689a0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 83d518aded30215684970e58d2868625fb8cd0e5
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790260"
---
# <a name="com-attributes"></a>Atributos COM

Os atributos COM injetam código para dar suporte a diversas áreas de desenvolvimento COM e desenvolvimento do .NET Framework common language runtime. Esses variam de áreas de implementação de interface personalizada e suporte às interfaces existentes para dar suporte a eventos, métodos e propriedades de estoque. Além disso, o suporte pode ser encontrado para a composição e a implementação de controle ActiveX.
  
|Atributo|Descrição|
|---------------|-----------------|
|[aggregatable](aggregatable.md)|Indica se um controle pode ser agregado por outro controle.|
|[aggregates](aggregates.md)|Indica que um controle agrega a classe de destino.|
|[coclass](coclass.md)|Cria um objeto COM, que pode implementar uma interface COM.|
|[com_interface_entry](com-interface-entry-cpp.md)|Adiciona uma entrada de interface para um mapa COM.|
|[implements_category](implements-category.md)|Especifica as categorias de componentes implementados para a classe.|
|[progid](progid.md)|Define o ProgID de um controle.|
|[rdx](rdx.md)|Cria ou modifica uma chave do registro.|
|[registration_script](registration-script.md)|Executa o script de registro especificado.|
|[requires_category](requires-category.md)|Especifica as categorias de componente necessário para a classe.|
|[support_error_info](support-error-info.md)|Dá suporte a relatórios de erros para o objeto de destino.|
|[synchronize](synchronize.md)|Sincroniza o acesso a um método.|
|[Threading](threading-cpp.md)|Especifica o modelo de threading para um objeto COM.|
|[vi_progid](vi-progid.md)|Define um ProgID independente de versão para um controle.|
  
## <a name="see-also"></a>Consulte também

[Atributos por grupo](attributes-by-group.md)