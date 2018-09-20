---
title: Atributos COM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 71ff4e3fdb80b48e306e543bdb683c3dd2b26ec3
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46443326"
---
# <a name="com-attributes"></a>Atributos COM
Os atributos COM injetam código para dar suporte a diversas áreas de desenvolvimento COM e desenvolvimento do .NET Framework common language runtime. Esses variam de áreas de implementação de interface personalizada e suporte às interfaces existentes para dar suporte a eventos, métodos e propriedades de estoque. Além disso, o suporte pode ser encontrado para a composição e a implementação de controle ActiveX.
  
|Atributo|Descrição|
|---------------|-----------------|
|[aggregatable](../windows/aggregatable.md)|Indica se um controle pode ser agregado por outro controle.|
|[aggregates](../windows/aggregates.md)|Indica que um controle agrega a classe de destino.|
|[coclass](../windows/coclass.md)|Cria um objeto COM, que pode implementar uma interface COM.|
|[com_interface_entry](../windows/com-interface-entry-cpp.md)|Adiciona uma entrada de interface para um mapa COM.|
|[implements_category](../windows/implements-category.md)|Especifica as categorias de componentes implementados para a classe.|
|[progid](../windows/progid.md)|Define o ProgID de um controle.|
|[rdx](../windows/rdx.md)|Cria ou modifica uma chave do registro.|
|[registration_script](../windows/registration-script.md)|Executa o script de registro especificado.|
|[requires_category](../windows/requires-category.md)|Especifica as categorias de componente necessário para a classe.|
|[support_error_info](../windows/support-error-info.md)|Dá suporte a relatórios de erros para o objeto de destino.|
|[synchronize](../windows/synchronize.md)|Sincroniza o acesso a um método.|
|[Threading](../windows/threading-cpp.md)|Especifica o modelo de threading para um objeto COM.|
|[vi_progid](../windows/vi-progid.md)|Define um ProgID independente de versão para um controle.|
  
## <a name="see-also"></a>Consulte também

[Atributos por grupo](../windows/attributes-by-group.md)