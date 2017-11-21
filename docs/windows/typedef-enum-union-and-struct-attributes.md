---
title: TypeDef, Enum, Union e Struct atributos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- union attributes
- attributes [C++], reference topics
- struct attributes
- typedef attributes
- enum attributes
ms.assetid: f8a4fe94-dc02-4aed-bc31-3e500d42f4c7
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 9bba47c5c0ea12ae7c1ae4f57adc24b58166ded8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="typedef-enum-union-and-struct-attributes"></a>Atributos Typedef, Enum, Union e Struct
Os atributos a seguir se aplicam ao [typedef](http://msdn.microsoft.com/en-us/cc96cf26-ba93-4179-951e-695d1f5fdcf1), [struct](../cpp/struct-cpp.md), e [enum](../cpp/enumerations-cpp.md) palavras-chave C++.  
  
### <a name="typedef"></a>typedef  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|[case](../windows/case-cpp.md)|Usado com o [switch_type](../windows/switch-type.md) atributo em uma **união**.|  
|[personalizado](../windows/custom-cpp.md)|Permite que você defina seu próprio atributo.|  
|[export](../windows/export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|  
|[first_is](../windows/first-is.md)|Especifica o índice do primeiro elemento de matriz a ser transmitido.|  
|[helpcontext](../windows/helpcontext.md)|Especifica uma ID de contexto que permite que usuários exibir informações sobre este elemento no arquivo de Ajuda.|  
|[helpfile](../windows/helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|  
|[helpstring](../windows/helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual se aplica.|  
|[library_block](../windows/library-block.md)|Coloca uma construção dentro do bloco de biblioteca do arquivo. idl.|  
|[ptr](../windows/ptr.md)|Designa um ponteiro como um ponteiro completo.|  
|[public](../windows/public-cpp-attributes.md)|Garante que um typedef para ir para a biblioteca de tipo mesmo que não é referenciado de dentro do arquivo. idl.|  
|[ref](../windows/ref-cpp.md)|Identifica um ponteiro de referência.|  
|[switch_is](../windows/switch-is.md)|Especifica a expressão ou identificador atuando como o discriminador de união que seleciona o membro de união.|  
|[switch_type](../windows/switch-type.md)|Identifica o tipo da variável usado como o discriminador de união.|  
|[unique](../windows/unique-cpp.md)|Especifica um ponteiro exclusivo.|  
|[wire_marshal](../windows/wire-marshal.md)|Especifica um tipo de dados que será usado para a transmissão em vez de um tipo de dados específicos do aplicativo.|  
  
### <a name="enum"></a>enum  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|[personalizado](../windows/custom-cpp.md)|Permite que você defina seu próprio atributo.|  
|[export](../windows/export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|  
|[UUID](../windows/uuid-cpp-attributes.md)|Especifica a ID exclusiva de uma classe ou interface.|  
|[v1_enum](../windows/v1-enum.md)|Direciona-se de que o tipo enumerado especificado ser transmitidas como uma entidade de 32 bits, em vez do padrão de 16 bits.|  
  
### <a name="union"></a>union  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|[personalizado](../windows/custom-cpp.md)|Permite que você defina seu próprio atributo.|  
|[export](../windows/export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|  
|[first_is](../windows/first-is.md)|Especifica o índice do primeiro elemento de matriz a ser transmitido.|  
|[last_is](../windows/last-is.md)|Especifica o índice do último elemento de matriz a ser transmitido.|  
|[length_is](../windows/length-is.md)|Especifica o número de elementos de matriz a ser transmitido.|  
|[max_is](../windows/max-is.md)|Designa o valor máximo para um índice de matriz válida.|  
|[size_is](../windows/size-is.md)|Especifica o tamanho da memória alocada para ponteiros de tamanhos, tamanho ponteiros para ponteiros de tamanhos e único ou matrizes multidimensionais.|  
|[unique](../windows/unique-cpp.md)|Especifica um ponteiro exclusivo.|  
|[UUID](../windows/uuid-cpp-attributes.md)|Especifica a ID exclusiva de uma classe ou interface.|  
  
### <a name="nonencapsulated-union"></a>União nonencapsulated  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|[ms_union](../windows/ms-union.md)|Controla o alinhamento de representação de dados de rede de uniões nonencapsulated.|  
|[no_injected_text](../windows/no-injected-text.md)|Impede que o compilador injeção de código como resultado do uso do atributo.|  
  
### <a name="struct"></a>struct  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|[aggregatable](../windows/aggregatable.md)|Indica que a classe oferece suporte à agregação.|  
|[aggregates](../windows/aggregates.md)|Indica que um controle agrega a classe de destino.|  
|[appobject](../windows/appobject.md)|Identifica o coclass como um objeto de aplicativo, que está associado um aplicativo completo .exe e indica que as funções e propriedades da coclass estão globalmente disponíveis na biblioteca de tipo.|  
|[coclass](../windows/coclass.md)|Cria um controle ActiveX.|  
|[com_interface_entry](../windows/com-interface-entry-cpp.md)|Adiciona uma entrada de interface para um mapa de COM.|  
|[control](../windows/control.md)|Especifica que o tipo definido pelo usuário é um controle.|  
|[personalizado](../windows/custom-cpp.md)|Permite que você defina seu próprio atributo.|  
|[db_column](../windows/db-column.md)|Associa uma coluna especificada para o conjunto de linhas.|  
|[db_command](../windows/db-command.md)|Cria um comando OLE DB.|  
|[db_param](../windows/db-param.md)|Associa a variável de membro especificado com um parâmetro de entrada ou saído e delimita a variável.|  
|[db_source](../windows/db-source.md)|Cria uma conexão com uma fonte de dados.|  
|[db_table](../windows/db-table.md)|Abre uma tabela de banco de dados OLE.|  
|[default](../windows/default-cpp.md)|Indica que o personalizado ou dispinterface definidos em uma coclass representa a interface de programação padrão.|  
|[defaultvtable](../windows/defaultvtable.md)|Define uma interface de interface vtable padrão para um controle.|  
|[event_receiver](../windows/event-receiver.md)|Cria um receptor de evento.|  
|[event_source](../windows/event-source.md)|Cria uma origem de evento.|  
|[export](../windows/export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|  
|[first_is](../windows/first-is.md)|Especifica o índice do primeiro elemento de matriz a ser transmitido.|  
|[hidden](../windows/hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|  
|[implements_category](../windows/implements-category.md)|Especifica as categorias de componente implementado para a classe.|  
|[last_is](../windows/last-is.md)|Especifica o índice do último elemento de matriz a ser transmitido.|  
|[length_is](../windows/length-is.md)|Especifica o número de elementos de matriz a ser transmitido.|  
|[max_is](../windows/max-is.md)|Designa o valor máximo para um índice de matriz válida.|  
|[requires_category](../windows/requires-category.md)|Especifica as categorias de componente necessário da classe de destino.|  
|[size_is](../windows/size-is.md)|Especifica o tamanho da memória alocada para ponteiros de tamanhos, tamanho ponteiros para ponteiros de tamanhos e único ou matrizes multidimensionais.|  
|[código-fonte](../windows/source-cpp.md)|Em uma classe, especifica as interfaces de origem do objeto COM para pontos de conexão. Uma propriedade ou método, indica que o membro retorna um objeto ou uma VARIANTE é uma origem de eventos.|  
|[Threading](../windows/threading-cpp.md)|Especifica o modelo de threading para um objeto COM.|  
|[unique](../windows/unique-cpp.md)|Especifica um ponteiro exclusivo.|  
|[UUID](../windows/uuid-cpp-attributes.md)|Especifica a ID exclusiva de uma classe ou interface.|  
|[version](../windows/version-cpp.md)|Identifica uma versão específica entre várias versões de uma classe.|  
|[vi_progid](../windows/vi-progid.md)|Especifica uma forma independente de versão de ProgID.|  
  
## <a name="see-also"></a>Consulte também  
 [Atributos por uso](../windows/attributes-by-usage.md)