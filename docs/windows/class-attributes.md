---
title: "Class Attributes | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "attributes [C++], class attributes"
  - "class attributes"
ms.assetid: fad04ea1-d8ff-46d4-bb42-2b4500a6ab60
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Class Attributes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os atributos a seguir aplicam\-se para o  [classe](../cpp/class-cpp.md) palavra\-chave do C\+\+.  
  
|Atributo|Descrição|  
|--------------|---------------|  
|[agregável](../Topic/aggregatable.md)|Indica que a classe oferece suporte à agregação.|  
|[agregações](../windows/aggregates.md)|Indica que um controle agrega a classe de destino.|  
|[appobject](../Topic/appobject.md)|Identifica o coclass como um objeto de aplicativo, que é associado a um aplicativo. exe completo e indica que as funções e propriedades do coclass estão disponíveis globalmente nesta biblioteca de tipo.|  
|[Caso](../windows/case-cpp.md)|Usado com o  [switch\_type](../windows/switch-type.md) atributo em uma união.|  
|[coclass](../windows/coclass.md)|Cria um controle ActiveX.|  
|[com\_interface\_entry](../Topic/com_interface_entry%20\(C++\).md)|Adiciona uma entrada de interface a um mapa de COM.|  
|[controle](../windows/control.md)|Especifica que o tipo definido pelo usuário é um controle.|  
|[personalizado](../windows/custom-cpp.md)|Permite definir o seu próprio atributo.|  
|[db\_command](../windows/db-command.md)|Cria um comando OLE DB.|  
|[db\_param](../windows/db-param.md)|Associa a variável de membro especificada com um parâmetro de entrada ou de saída e delimita a variável.|  
|[db\_source](../windows/db-source.md)|Cria a conexão com a fonte de dados.|  
|[db\_table](../windows/db-table.md)|Abre uma tabela OLE DB.|  
|[Padrão](../windows/default-cpp.md)|Indica que o personalizado ou um dispinterface definido dentro de um coclass representa a interface de programação padrão.|  
|[defaultvtable](../windows/defaultvtable.md)|Define uma interface como interface padrão vtable para um controle.|  
|[event\_receiver](../windows/event-receiver.md)|Cria um receptor de eventos.|  
|[EVENT\_SOURCE](../windows/event-source.md)|Cria uma fonte de evento.|  
|[HelpContext](../windows/helpcontext.md)|Especifica uma identificação de contexto que permite que as informações de modo de exibição do usuário sobre este elemento no arquivo de Ajuda.|  
|[arquivo de ajuda](../Topic/helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|  
|[helpstringcontext](../windows/helpstringcontext.md)|Especifica a ID de um tópico da ajuda em um arquivo .hlp ou .chm.|  
|[HelpString](../windows/helpstring.md)|Especifica a string que é usada para descrever o elemento a que se aplica.|  
|[oculto](../Topic/hidden.md)|Indica que o item existe mas não deve ser exibido em um navegador orientado a usuário.|  
|[implementa](../Topic/implements%20\(C++\).md)|Especifica as interfaces de despacho que são forçados a ser membros do coclass de IDL.|  
|[implements\_category](../Topic/implements_category.md)|Especifica as categorias de componente implementada para a classe.|  
|[módulo](../windows/module-cpp.md)|Define o bloco de biblioteca no arquivo. idl.|  
|[noncreatable](../windows/noncreatable.md)|Define um objeto que não pode ser instanciado por si só.|  
|[ProgID](../Topic/progid.md)|Define o ProgID de um controle.|  
|[registration\_script](../windows/registration-script.md)|Executa o script de registro especificado.|  
|[requestedit](../windows/requestedit.md)|Indica que a propriedade oferece suporte a  **OnRequestEdit** notificação.|  
|[fonte](../Topic/source%20\(C++\).md)|Especifica as interfaces de origem do controle para pontos de conexão em uma classe.  Em uma propriedade ou método, o  **origem**  atributo indica que o membro retorna um objeto ou uma VARIANTE que é uma fonte de eventos.|  
|[support\_error\_info](../windows/support-error-info.md)|Oferece suporte a relatórios de erro para o objeto de destino.|  
|[Threading](../windows/threading-cpp.md)|Especifica o modelo de segmentação para um controle.|  
|[UUID](../windows/uuid-cpp-attributes.md)|Especifica a identificação exclusiva de uma classe ou interface.|  
|[version](../windows/version-cpp.md)|Identifica uma versão específica entre várias versões de uma classe.|  
|[vi\_progid](../windows/vi-progid.md)|Especifica um formulário independente de versão de ProgID.|  
  
## Consulte também  
 [Attributes by Usage](../windows/attributes-by-usage.md)