---
title: Atributos de classeC++ (com)
ms.date: 10/02/2018
helpviewer_keywords:
- attributes [C++/CLI], class attributes
ms.assetid: fad04ea1-d8ff-46d4-bb42-2b4500a6ab60
ms.openlocfilehash: 5e10b7831e59211b73ce947ac21e43bc1a8af1c9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80167310"
---
# <a name="class-attributes"></a>Atributos de classe

Os atributos a seguir se aplicam à palavra-chave [Class](../../cpp/class-cpp.md) C++ .

|Atributo|DESCRIÇÃO|
|---------------|-----------------|
|[aggregatable](aggregatable.md)|Indica que a classe oferece suporte à agregação.|
|[aggregates](aggregates.md)|Indica que um controle agrega a classe de destino.|
|[appobject](appobject.md)|Identifica a coclass como um objeto Application, que está associado a um aplicativo Full. exe e indica que as funções e as propriedades da coclass estão disponíveis globalmente nesta biblioteca de tipos.|
|[case](case-cpp.md)|Usado com o atributo [switch_type](switch-type.md) em uma Union.|
|[coclass](coclass.md)|Cria um controle ActiveX.|
|[com_interface_entry](com-interface-entry-cpp.md)|Adiciona uma entrada de interface a um mapa COM.|
|[control](control.md)|Especifica que o tipo definido pelo usuário é um controle.|
|[custom](custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[db_command](db-command.md)|Cria um comando OLE DB.|
|[db_param](db-param.md)|Associa a variável de membro especificada com um parâmetro de entrada ou saída e delimita a variável.|
|[db_source](db-source.md)|Cria uma conexão com uma fonte de dados.|
|[db_table](db-table.md)|Abre uma tabela OLE DB.|
|[default](default-cpp.md)|Indica que a dispinterface ou personalizada definida em uma coclass representa a interface de programação padrão.|
|[defaultvtable](defaultvtable.md)|Define uma interface como a interface vtable padrão para um controle.|
|[event_receiver](event-receiver.md)|Cria um receptor de eventos.|
|[event_source](event-source.md)|Cria uma origem de evento.|
|[helpcontext](helpcontext.md)|Especifica uma ID de contexto que permite ao usuário exibir informações sobre esse elemento no arquivo de **ajuda** .|
|[helpfile](helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|
|[helpstringcontext](helpstringcontext.md)|Especifica a ID de um tópico da ajuda em um arquivo. hlp ou. chm.|
|[helpstring](helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|
|[hidden](hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[implements](implements-cpp.md)|Especifica as interfaces de expedição que são forçadas a serem membros da coclasse IDL.|
|[implements_category](implements-category.md)|Especifica as categorias de componente implementadas para a classe.|
|[module](module-cpp.md)|Define o bloco de biblioteca no arquivo. idl.|
|[noncreatable](noncreatable.md)|Define um objeto que não pode ser instanciado por si só.|
|[progid](progid.md)|Define o ProgID de um controle.|
|[registration_script](registration-script.md)|Executa o script de registro especificado.|
|[requestedit](requestedit.md)|Indica que a propriedade dá suporte à notificação `OnRequestEdit`.|
|[origem](source-cpp.md)|Especifica as interfaces de origem do controle para pontos de conexão em uma classe. Em uma propriedade ou método, o atributo `source` indica que o membro retorna um objeto ou `VARIANT` que é uma fonte de eventos.|
|[support_error_info](support-error-info.md)|Dá suporte ao relatório de erros para o objeto de destino.|
|[threading](threading-cpp.md)|Especifica o modelo de threading para um controle.|
|[uuid](uuid-cpp-attributes.md)|Especifica a ID exclusiva para uma classe ou interface.|
|[version](version-cpp.md)|Identifica uma versão específica entre várias versões de uma classe.|
|[vi_progid](vi-progid.md)|Especifica uma forma independente de versão do ProgID.|

## <a name="see-also"></a>Confira também

[Atributos por uso](attributes-by-usage.md)
