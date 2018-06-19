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
- attributes [C++], class attributes
- class attributes
ms.assetid: fad04ea1-d8ff-46d4-bb42-2b4500a6ab60
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8a932fdb1ef1d9e2af2acace901feaa95b6216d1
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33861435"
---
# <a name="class-attributes"></a>Atributos de classe
Os atributos a seguir se aplicam ao [classe](../cpp/class-cpp.md) palavra-chave do C++.  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|[aggregatable](../windows/aggregatable.md)|Indica que a classe oferece suporte à agregação.|  
|[aggregates](../windows/aggregates.md)|Indica que um controle agrega a classe de destino.|  
|[appobject](../windows/appobject.md)|Identifica o coclass como um objeto de aplicativo, que está associado um aplicativo completo .exe e indica que as funções e propriedades da coclass estão globalmente disponíveis na biblioteca de tipo.|  
|[case](../windows/case-cpp.md)|Usado com o [switch_type](../windows/switch-type.md) atributo em uma união.|  
|[coclass](../windows/coclass.md)|Cria um controle ActiveX.|  
|[com_interface_entry](../windows/com-interface-entry-cpp.md)|Adiciona uma entrada de interface para um mapa de COM.|  
|[control](../windows/control.md)|Especifica que o tipo definido pelo usuário é um controle.|  
|[custom](../windows/custom-cpp.md)|Permite que você defina seu próprio atributo.|  
|[db_command](../windows/db-command.md)|Cria um comando OLE DB.|  
|[db_param](../windows/db-param.md)|Associa a variável de membro especificado com um parâmetro de entrada ou saído e delimita a variável.|  
|[db_source](../windows/db-source.md)|Cria uma conexão com uma fonte de dados.|  
|[db_table](../windows/db-table.md)|Abre uma tabela de banco de dados OLE.|  
|[default](../windows/default-cpp.md)|Indica que o personalizado ou dispinterface definidos em uma coclass representa a interface de programação padrão.|  
|[defaultvtable](../windows/defaultvtable.md)|Define uma interface de interface vtable padrão para um controle.|  
|[event_receiver](../windows/event-receiver.md)|Cria um receptor de evento.|  
|[event_source](../windows/event-source.md)|Cria uma origem de evento.|  
|[helpcontext](../windows/helpcontext.md)|Especifica uma ID de contexto que permite que usuários exibir informações sobre este elemento no arquivo de Ajuda.|  
|[helpfile](../windows/helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|  
|[helpstringcontext](../windows/helpstringcontext.md)|Especifica a ID de um tópico da Ajuda em um arquivo. hlp ou. chm.|  
|[helpstring](../windows/helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual se aplica.|  
|[hidden](../windows/hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|  
|[implementa](../windows/implements-cpp.md)|Especifica as interfaces de expedição são forçadas ao ser membros da coclass IDL.|  
|[implements_category](../windows/implements-category.md)|Especifica as categorias de componente implementado para a classe.|  
|[Módulo](../windows/module-cpp.md)|Define o bloco de biblioteca no arquivo. idl.|  
|[noncreatable](../windows/noncreatable.md)|Define um objeto que não pode ser instanciado por si só.|  
|[progid](../windows/progid.md)|Define o ProgID de um controle.|  
|[registration_script](../windows/registration-script.md)|Executa o script de registro especificado.|  
|[requestedit](../windows/requestedit.md)|Indica que a propriedade oferece suporte a **OnRequestEdit** notificação.|  
|[Código-fonte](../windows/source-cpp.md)|Especifica as interfaces de origem do controle para pontos de conexão em uma classe. Em uma propriedade ou método, o **fonte** atributo indica que o membro retorna um objeto ou uma VARIANTE é uma origem de eventos.|  
|[support_error_info](../windows/support-error-info.md)|Dá suporte a relatórios de erros para o objeto de destino.|  
|[Threading](../windows/threading-cpp.md)|Especifica o modelo de threading para um controle.|  
|[uuid](../windows/uuid-cpp-attributes.md)|Especifica a ID exclusiva de uma classe ou interface.|  
|[version](../windows/version-cpp.md)|Identifica uma versão específica entre várias versões de uma classe.|  
|[vi_progid](../windows/vi-progid.md)|Especifica uma forma independente de versão de ProgID.|  
  
## <a name="see-also"></a>Consulte também  
 [Atributos por uso](../windows/attributes-by-usage.md)