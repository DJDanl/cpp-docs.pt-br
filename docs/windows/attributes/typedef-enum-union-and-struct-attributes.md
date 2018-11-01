---
title: TypeDef, Enum, Union e Struct atributos (COM C++)
ms.date: 10/02/2018
helpviewer_keywords:
- union attributes
- attributes [C++/CLI], reference topics
ms.assetid: f8a4fe94-dc02-4aed-bc31-3e500d42f4c7
ms.openlocfilehash: 289935c3651535b5f935624dc33246fbe83a4ceb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50631056"
---
# <a name="typedef-enum-union-and-struct-attributes"></a>Atributos Typedef, Enum, Union e Struct

Os atributos a seguir se aplicam para o [typedef](../../cpp/aliases-and-typedefs-cpp.md), [struct](../../cpp/struct-cpp.md), e [enum](../../cpp/enumerations-cpp.md) palavras-chave C++.

### <a name="typedef"></a>typedef

|Atributo|Descrição|
|---------------|-----------------|
|[case](case-cpp.md)|Usado com o [switch_type](switch-type.md) atributo em uma **união**.|
|[custom](custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[export](export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|
|[first_is](first-is.md)|Especifica o índice do primeiro elemento da matriz a ser transmitido.|
|[helpcontext](helpcontext.md)|Especifica uma ID de contexto que permite que usuários exibir informações sobre esse elemento no arquivo de Ajuda.|
|[helpfile](helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|
|[helpstring](helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|
|[library_block](library-block.md)|Coloca uma construção de dentro do bloco de biblioteca do arquivo. idl.|
|[ptr](ptr.md)|Designa um ponteiro como um ponteiro completo.|
|[public](public-cpp-attributes.md)|Garante que um typedef entra em biblioteca de tipos, mesmo se ele não é referenciado de dentro do arquivo. idl.|
|[ref](ref-cpp.md)|Identifica um ponteiro de referência.|
|[switch_is](switch-is.md)|Especifica a expressão ou um identificador que atua como o discriminador de união que seleciona o membro de união.|
|[switch_type](switch-type.md)|Identifica o tipo da variável usada como o discriminador de união.|
|[unique](unique-cpp.md)|Especifica um ponteiro exclusivo.|
|[wire_marshal](wire-marshal.md)|Especifica um tipo de dados que será usado para transmissão em vez de um tipo de dados específicos do aplicativo.|

### <a name="enum"></a>enum

|Atributo|Descrição|
|---------------|-----------------|
|[custom](custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[export](export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|
|[uuid](uuid-cpp-attributes.md)|Especifica a ID exclusiva para uma classe ou interface.|
|[v1_enum](v1-enum.md)|Direciona-se de que o tipo enumerado especificado ser transmitidas como uma entidade de 32 bits, em vez do padrão de 16 bits.|

### <a name="union"></a>union

|Atributo|Descrição|
|---------------|-----------------|
|[custom](custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[export](export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|
|[first_is](first-is.md)|Especifica o índice do primeiro elemento da matriz a ser transmitido.|
|[last_is](last-is.md)|Especifica o índice do último elemento da matriz a ser transmitido.|
|[length_is](length-is.md)|Especifica o número de elementos da matriz a ser transmitido.|
|[max_is](max-is.md)|Designa o valor máximo para um índice de matriz válida.|
|[size_is](size-is.md)|Especifica o tamanho da memória alocada para ponteiros de tamanho, tamanho de ponteiros para ponteiros de tamanho e único ou matrizes multidimensionais.|
|[unique](unique-cpp.md)|Especifica um ponteiro exclusivo.|
|[uuid](uuid-cpp-attributes.md)|Especifica a ID exclusiva para uma classe ou interface.|

### <a name="nonencapsulated-union"></a>União nonencapsulated

|Atributo|Descrição|
|---------------|-----------------|
|[ms_union](ms-union.md)|Controla o alinhamento de representação de dados de rede de uniões nonencapsulated.|
|[no_injected_text](no-injected-text.md)|Impede que o compilador injetando código como resultado do uso do atributo.|

### <a name="struct"></a>struct

|Atributo|Descrição|
|---------------|-----------------|
|[aggregatable](aggregatable.md)|Indica que a classe oferece suporte à agregação.|
|[aggregates](aggregates.md)|Indica que um controle agrega a classe de destino.|
|[appobject](appobject.md)|Identifica a coclass como um objeto de aplicativo, que é associado a um aplicativo completo .exe e indica que as funções e propriedades da coclass estão globalmente disponíveis na biblioteca de tipo.|
|[coclass](coclass.md)|Cria um controle ActiveX.|
|[com_interface_entry](com-interface-entry-cpp.md)|Adiciona uma entrada de interface para um mapa COM.|
|[control](control.md)|Especifica que o tipo definido pelo usuário é um controle.|
|[custom](custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[db_column](db-column.md)|Associa uma coluna especificada para o conjunto de linhas.|
|[db_command](db-command.md)|Cria um comando OLE DB.|
|[db_param](db-param.md)|Associa a variável de membro especificado com um parâmetro de entrada ou saído e delimita a variável.|
|[db_source](db-source.md)|Cria uma conexão a uma fonte de dados.|
|[db_table](db-table.md)|Abre uma tabela de OLE DB.|
|[default](default-cpp.md)|Indica que o personalizado ou dispinterface definido dentro de uma coclass representa a interface de programação padrão.|
|[defaultvtable](defaultvtable.md)|Define uma interface como a interface de vtable padrão para um controle.|
|[event_receiver](event-receiver.md)|Cria um receptor de eventos.|
|[event_source](event-source.md)|Cria uma origem de evento.|
|[export](export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|
|[first_is](first-is.md)|Especifica o índice do primeiro elemento da matriz a ser transmitido.|
|[hidden](hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[implements_category](implements-category.md)|Especifica as categorias de componentes implementados para a classe.|
|[last_is](last-is.md)|Especifica o índice do último elemento da matriz a ser transmitido.|
|[length_is](length-is.md)|Especifica o número de elementos da matriz a ser transmitido.|
|[max_is](max-is.md)|Designa o valor máximo para um índice de matriz válida.|
|[requires_category](requires-category.md)|Especifica as categorias de componente necessário da classe de destino.|
|[size_is](size-is.md)|Especifica o tamanho da memória alocada para ponteiros de tamanho, tamanho de ponteiros para ponteiros de tamanho e único ou matrizes multidimensionais.|
|[source](source-cpp.md)|Em uma classe, especifica as interfaces de origem do objeto COM para pontos de conexão. Em uma propriedade ou método, indica que o membro retorna um objeto ou uma VARIANTE que é uma origem de eventos.|
|[threading](threading-cpp.md)|Especifica o modelo de threading para um objeto COM.|
|[unique](unique-cpp.md)|Especifica um ponteiro exclusivo.|
|[uuid](uuid-cpp-attributes.md)|Especifica a ID exclusiva para uma classe ou interface.|
|[version](version-cpp.md)|Identifica uma versão específica entre várias versões de uma classe.|
|[vi_progid](vi-progid.md)|Especifica uma forma independente de versão do ProgID.|

## <a name="see-also"></a>Consulte também

[Atributos por uso](attributes-by-usage.md)