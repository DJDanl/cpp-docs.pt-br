---
title: Atributos COM
ms.date: 10/03/2018
helpviewer_keywords:
- attributes [C++/CLI], reference topics
- attributes [COM]
- COM, attributes
ms.assetid: 52a5dd70-e8be-4bba-afd6-daf90fe689a0
ms.openlocfilehash: fa7e279f6b7c9c0932d404c336bcfd89bfd553a3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50644087"
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
|[threading](threading-cpp.md)|Especifica o modelo de threading para um objeto COM.|
|[vi_progid](vi-progid.md)|Define um ProgID independente de versão para um controle.|

## <a name="see-also"></a>Consulte também

[Atributos por grupo](attributes-by-group.md)