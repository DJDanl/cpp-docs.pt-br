---
title: Atributos de classe (COM C++)
ms.date: 10/02/2018
helpviewer_keywords:
- attributes [C++/CLI], class attributes
ms.assetid: fad04ea1-d8ff-46d4-bb42-2b4500a6ab60
ms.openlocfilehash: bdc689107eb973b9701e3f1fbe37a10aa6ae8d85
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50448861"
---
# <a name="class-attributes"></a>Atributos de classe

Os atributos a seguir se aplicam para o [classe](../../cpp/class-cpp.md) palavra-chave C++.

|Atributo|Descrição|
|---------------|-----------------|
|[aggregatable](aggregatable.md)|Indica que a classe oferece suporte à agregação.|
|[aggregates](aggregates.md)|Indica que um controle agrega a classe de destino.|
|[appobject](appobject.md)|Identifica a coclass como um objeto de aplicativo, que é associado a um aplicativo completo .exe e indica que as funções e propriedades da coclass estão globalmente disponíveis na biblioteca de tipo.|
|[case](case-cpp.md)|Usado com o [switch_type](switch-type.md) atributo em uma união.|
|[coclass](coclass.md)|Cria um controle ActiveX.|
|[com_interface_entry](com-interface-entry-cpp.md)|Adiciona uma entrada de interface para um mapa COM.|
|[control](control.md)|Especifica que o tipo definido pelo usuário é um controle.|
|[custom](custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[db_command](db-command.md)|Cria um comando OLE DB.|
|[db_param](db-param.md)|Associa a variável de membro especificado com um parâmetro de entrada ou saído e delimita a variável.|
|[db_source](db-source.md)|Cria uma conexão a uma fonte de dados.|
|[db_table](db-table.md)|Abre uma tabela de OLE DB.|
|[default](default-cpp.md)|Indica que o personalizado ou dispinterface definido dentro de uma coclass representa a interface de programação padrão.|
|[defaultvtable](defaultvtable.md)|Define uma interface como a interface de vtable padrão para um controle.|
|[event_receiver](event-receiver.md)|Cria um receptor de eventos.|
|[event_source](event-source.md)|Cria uma origem de evento.|
|[helpcontext](helpcontext.md)|Especifica uma ID de contexto que permite que usuários exibir informações sobre este elemento na **ajudar** arquivo.|
|[helpfile](helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|
|[helpstringcontext](helpstringcontext.md)|Especifica a ID do tópico da Ajuda em um arquivo. hlp ou. chm.|
|[helpstring](helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|
|[hidden](hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[implements](implements-cpp.md)|Especifica as interfaces de distribuição que são forçadas para serem membros da coclass IDL.|
|[implements_category](implements-category.md)|Especifica as categorias de componentes implementados para a classe.|
|[module](module-cpp.md)|Define o bloco de biblioteca no arquivo. idl.|
|[noncreatable](noncreatable.md)|Define um objeto que não pode ser instanciado por si só.|
|[progid](progid.md)|Define o ProgID de um controle.|
|[registration_script](registration-script.md)|Executa o script de registro especificado.|
|[requestedit](requestedit.md)|Indica que a propriedade oferece suporte a `OnRequestEdit` notificação.|
|[source](source-cpp.md)|Especifica as interfaces de origem do controle para pontos de conexão em uma classe. Em uma propriedade ou método, o `source` atributo indica que o membro retorna um objeto ou `VARIANT` que é uma origem de eventos.|
|[support_error_info](support-error-info.md)|Dá suporte a relatórios de erros para o objeto de destino.|
|[threading](threading-cpp.md)|Especifica o modelo de threading para um controle.|
|[uuid](uuid-cpp-attributes.md)|Especifica a ID exclusiva para uma classe ou interface.|
|[version](version-cpp.md)|Identifica uma versão específica entre várias versões de uma classe.|
|[vi_progid](vi-progid.md)|Especifica uma forma independente de versão do ProgID.|

## <a name="see-also"></a>Consulte também

[Atributos por uso](attributes-by-usage.md)