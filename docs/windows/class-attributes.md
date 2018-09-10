---
title: Atributos de classe | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++/CLI], class attributes
ms.assetid: fad04ea1-d8ff-46d4-bb42-2b4500a6ab60
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 60243373ea6b34ebceffd6f1ae21723e71e11bbb
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44313592"
---
# <a name="class-attributes"></a>Atributos de classe

Os atributos a seguir se aplicam para o [classe](../cpp/class-cpp.md) palavra-chave C++.

|Atributo|Descrição|
|---------------|-----------------|
|[aggregatable](../windows/aggregatable.md)|Indica que a classe oferece suporte à agregação.|
|[aggregates](../windows/aggregates.md)|Indica que um controle agrega a classe de destino.|
|[appobject](../windows/appobject.md)|Identifica a coclass como um objeto de aplicativo, que é associado a um aplicativo completo .exe e indica que as funções e propriedades da coclass estão globalmente disponíveis na biblioteca de tipo.|
|[case](../windows/case-cpp.md)|Usado com o [switch_type](../windows/switch-type.md) atributo em uma união.|
|[coclass](../windows/coclass.md)|Cria um controle ActiveX.|
|[com_interface_entry](../windows/com-interface-entry-cpp.md)|Adiciona uma entrada de interface para um mapa COM.|
|[control](../windows/control.md)|Especifica que o tipo definido pelo usuário é um controle.|
|[custom](../windows/custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[db_command](../windows/db-command.md)|Cria um comando OLE DB.|
|[db_param](../windows/db-param.md)|Associa a variável de membro especificado com um parâmetro de entrada ou saído e delimita a variável.|
|[db_source](../windows/db-source.md)|Cria uma conexão a uma fonte de dados.|
|[db_table](../windows/db-table.md)|Abre uma tabela de OLE DB.|
|[default](../windows/default-cpp.md)|Indica que o personalizado ou dispinterface definido dentro de uma coclass representa a interface de programação padrão.|
|[defaultvtable](../windows/defaultvtable.md)|Define uma interface como a interface de vtable padrão para um controle.|
|[event_receiver](../windows/event-receiver.md)|Cria um receptor de eventos.|
|[event_source](../windows/event-source.md)|Cria uma origem de evento.|
|[helpcontext](../windows/helpcontext.md)|Especifica uma ID de contexto que permite que usuários exibir informações sobre este elemento na **ajudar** arquivo.|
|[helpfile](../windows/helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|
|[helpstringcontext](../windows/helpstringcontext.md)|Especifica a ID do tópico da Ajuda em um arquivo. hlp ou. chm.|
|[helpstring](../windows/helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|
|[hidden](../windows/hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[Implementa](../windows/implements-cpp.md)|Especifica as interfaces de distribuição que são forçadas para serem membros da coclass IDL.|
|[implements_category](../windows/implements-category.md)|Especifica as categorias de componentes implementados para a classe.|
|[módulo](../windows/module-cpp.md)|Define o bloco de biblioteca no arquivo. idl.|
|[noncreatable](../windows/noncreatable.md)|Define um objeto que não pode ser instanciado por si só.|
|[progid](../windows/progid.md)|Define o ProgID de um controle.|
|[registration_script](../windows/registration-script.md)|Executa o script de registro especificado.|
|[requestedit](../windows/requestedit.md)|Indica que a propriedade oferece suporte a `OnRequestEdit` notificação.|
|[source](../windows/source-cpp.md)|Especifica as interfaces de origem do controle para pontos de conexão em uma classe. Em uma propriedade ou método, o `source` atributo indica que o membro retorna um objeto ou `VARIANT` que é uma origem de eventos.|
|[support_error_info](../windows/support-error-info.md)|Dá suporte a relatórios de erros para o objeto de destino.|
|[Threading](../windows/threading-cpp.md)|Especifica o modelo de threading para um controle.|
|[uuid](../windows/uuid-cpp-attributes.md)|Especifica a ID exclusiva para uma classe ou interface.|
|[version](../windows/version-cpp.md)|Identifica uma versão específica entre várias versões de uma classe.|
|[vi_progid](../windows/vi-progid.md)|Especifica uma forma independente de versão do ProgID.|

## <a name="see-also"></a>Consulte também

[Atributos por uso](../windows/attributes-by-usage.md)