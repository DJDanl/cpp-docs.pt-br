---
title: Atributos typedef, enum, Union e struct (C++ COM)
ms.date: 10/02/2018
helpviewer_keywords:
- union attributes
- attributes [C++/CLI], reference topics
ms.assetid: f8a4fe94-dc02-4aed-bc31-3e500d42f4c7
ms.openlocfilehash: 5e9eccd5e4464e92757d6dd78dd0f5187372ea3e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222102"
---
# <a name="typedef-enum-union-and-struct-attributes"></a>Atributos Typedef, Enum, Union e Struct

Os atributos a seguir se aplicam às palavras-chave [typedef](../../cpp/aliases-and-typedefs-cpp.md), [struct](../../cpp/struct-cpp.md)e [enum](../../cpp/enumerations-cpp.md) C++.

### <a name="typedef"></a>typedef

|Atributo|Descrição|
|---------------|-----------------|
|[casos](case-cpp.md)|Usado com o atributo [switch_type](switch-type.md) em um **`union`** .|
|[Personalizar](custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[Export](export.md)|Faz com que uma estrutura de dados seja colocada no arquivo. idl.|
|[first_is](first-is.md)|Especifica o índice do primeiro elemento de matriz a ser transmitido.|
|[helpcontext](helpcontext.md)|Especifica uma ID de contexto que permite ao usuário exibir informações sobre esse elemento no arquivo de ajuda.|
|[helpfile](helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|
|[helpstring](helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|
|[library_block](library-block.md)|Coloca uma construção dentro do bloco de biblioteca do arquivo. idl.|
|[ptr](ptr.md)|Designa um ponteiro como um ponteiro completo.|
|[público](public-cpp-attributes.md)|Garante que um typedef entrará na biblioteca de tipos, mesmo que não seja referenciado de dentro do arquivo. idl.|
|[ref](ref-cpp.md)|Identifica um ponteiro de referência.|
|[switch_is](switch-is.md)|Especifica a expressão ou o identificador que atua como o discriminante de União que seleciona o membro da União.|
|[switch_type](switch-type.md)|Identifica o tipo da variável usada como discriminante de União.|
|[unique](unique-cpp.md)|Especifica um ponteiro exclusivo.|
|[wire_marshal](wire-marshal.md)|Especifica um tipo de dados que será usado para transmissão em vez de um tipo de dados específico do aplicativo.|

### <a name="enum"></a>enum

|Atributo|Descrição|
|---------------|-----------------|
|[Personalizar](custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[Export](export.md)|Faz com que uma estrutura de dados seja colocada no arquivo. idl.|
|[uuid](uuid-cpp-attributes.md)|Especifica a ID exclusiva para uma classe ou interface.|
|[v1_enum](v1-enum.md)|Direciona que o tipo enumerado especificado seja transmitido como uma entidade de 32 bits, em vez do padrão de 16 bits.|

### <a name="union"></a>union

|Atributo|Descrição|
|---------------|-----------------|
|[Personalizar](custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[Export](export.md)|Faz com que uma estrutura de dados seja colocada no arquivo. idl.|
|[first_is](first-is.md)|Especifica o índice do primeiro elemento de matriz a ser transmitido.|
|[last_is](last-is.md)|Especifica o índice do último elemento de matriz a ser transmitido.|
|[length_is](length-is.md)|Especifica o número de elementos da matriz a serem transmitidos.|
|[max_is](max-is.md)|Designa o valor máximo para um índice de matriz válido.|
|[size_is](size-is.md)|Especifica o tamanho da memória alocada para ponteiros de tamanho, ponteiros de tamanho para ponteiros de tamanho e matrizes de dimensão única ou multidimensional.|
|[unique](unique-cpp.md)|Especifica um ponteiro exclusivo.|
|[uuid](uuid-cpp-attributes.md)|Especifica a ID exclusiva para uma classe ou interface.|

### <a name="nonencapsulated-union"></a>União não encapsulada

|Atributo|Descrição|
|---------------|-----------------|
|[ms_union](ms-union.md)|Controla o alinhamento da representação de dados de rede de uniões não encapsuladas.|
|[no_injected_text](no-injected-text.md)|Impede que o compilador insira código como resultado do uso do atributo.|

### <a name="struct"></a>struct

|Atributo|Descrição|
|---------------|-----------------|
|[aggregatable](aggregatable.md)|Indica que a classe oferece suporte à agregação.|
|[agregações](aggregates.md)|Indica que um controle agrega a classe de destino.|
|[appobject](appobject.md)|Identifica a coclass como um objeto Application, que está associado a um aplicativo Full. exe e indica que as funções e as propriedades da coclass estão disponíveis globalmente nesta biblioteca de tipos.|
|[coclass](coclass.md)|Cria um controle ActiveX.|
|[com_interface_entry](com-interface-entry-cpp.md)|Adiciona uma entrada de interface a um mapa COM.|
|[control](control.md)|Especifica que o tipo definido pelo usuário é um controle.|
|[Personalizar](custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[db_column](db-column.md)|Associa uma coluna especificada ao conjunto de linhas.|
|[db_command](db-command.md)|Cria um comando OLE DB.|
|[db_param](db-param.md)|Associa a variável de membro especificada com um parâmetro de entrada ou saída e delimita a variável.|
|[db_source](db-source.md)|Cria uma conexão com uma fonte de dados.|
|[db_table](db-table.md)|Abre uma tabela OLE DB.|
|[os](default-cpp.md)|Indica que a dispinterface ou personalizada definida em uma coclass representa a interface de programação padrão.|
|[defaultvtable](defaultvtable.md)|Define uma interface como a interface vtable padrão para um controle.|
|[event_receiver](event-receiver.md)|Cria um receptor de eventos.|
|[event_source](event-source.md)|Cria uma origem de evento.|
|[Export](export.md)|Faz com que uma estrutura de dados seja colocada no arquivo. idl.|
|[first_is](first-is.md)|Especifica o índice do primeiro elemento de matriz a ser transmitido.|
|[oculto](hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[implements_category](implements-category.md)|Especifica as categorias de componente implementadas para a classe.|
|[last_is](last-is.md)|Especifica o índice do último elemento de matriz a ser transmitido.|
|[length_is](length-is.md)|Especifica o número de elementos da matriz a serem transmitidos.|
|[max_is](max-is.md)|Designa o valor máximo para um índice de matriz válido.|
|[requires_category](requires-category.md)|Especifica as categorias de componente necessárias da classe de destino.|
|[size_is](size-is.md)|Especifica o tamanho da memória alocada para ponteiros de tamanho, ponteiros de tamanho para ponteiros de tamanho e matrizes de dimensão única ou multidimensional.|
|[source](source-cpp.md)|Em uma classe, especifica as interfaces de origem do objeto COM para pontos de conexão. Em uma propriedade ou método, indica que o membro retorna um objeto ou uma variante que é uma fonte de eventos.|
|[Threading](threading-cpp.md)|Especifica o modelo de threading para um objeto COM.|
|[unique](unique-cpp.md)|Especifica um ponteiro exclusivo.|
|[uuid](uuid-cpp-attributes.md)|Especifica a ID exclusiva para uma classe ou interface.|
|[version](version-cpp.md)|Identifica uma versão específica entre várias versões de uma classe.|
|[vi_progid](vi-progid.md)|Especifica uma forma independente de versão do ProgID.|

## <a name="see-also"></a>Confira também

[Atributos por uso](attributes-by-usage.md)
