---
title: Atributos COM
ms.date: 10/03/2018
helpviewer_keywords:
- attributes [C++/CLI], reference topics
- attributes [COM]
- COM, attributes
ms.assetid: 52a5dd70-e8be-4bba-afd6-daf90fe689a0
ms.openlocfilehash: 15225d23abb66b8aadd5f82b8429334356bdaa8d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168311"
---
# <a name="com-attributes"></a>Atributos COM

Os atributos COM injetam código para dar suporte a várias áreas de desenvolvimento COM e .NET Framework Common Language Runtime desenvolvimento. Essas áreas variam de implementação de interface personalizada e suporte de interfaces existentes para dar suporte a propriedades, métodos e eventos de ações. Além disso, o suporte pode ser encontrado para implementação de controle de composição e ActiveX.

|Atributo|DESCRIÇÃO|
|---------------|-----------------|
|[aggregatable](aggregatable.md)|Indica que um controle pode ser agregado por outro controle.|
|[aggregates](aggregates.md)|Indica que um controle agrega a classe de destino.|
|[coclass](coclass.md)|Cria um objeto COM, que pode implementar uma interface COM.|
|[com_interface_entry](com-interface-entry-cpp.md)|Adiciona uma entrada de interface a um mapa COM.|
|[implements_category](implements-category.md)|Especifica as categorias de componente implementadas para a classe.|
|[progid](progid.md)|Define o ProgID de um controle.|
|[rdx](rdx.md)|Cria ou modifica uma chave do registro.|
|[registration_script](registration-script.md)|Executa o script de registro especificado.|
|[requires_category](requires-category.md)|Especifica as categorias de componente necessárias para a classe.|
|[support_error_info](support-error-info.md)|Dá suporte ao relatório de erros para o objeto de destino.|
|[synchronize](synchronize.md)|Sincroniza o acesso a um método.|
|[threading](threading-cpp.md)|Especifica o modelo de threading para um objeto COM.|
|[vi_progid](vi-progid.md)|Define um ProgID independente de versão para um controle.|

## <a name="see-also"></a>Confira também

[Atributos por grupo](attributes-by-group.md)
