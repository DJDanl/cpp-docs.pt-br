---
title: Atributos do métodoC++ (com)
ms.date: 10/02/2018
helpviewer_keywords:
- method attributes
- attributes [C++/CLI], reference topics
ms.assetid: b2313352-480d-488b-8c35-6242ffd3a549
ms.openlocfilehash: c9823869be96f53a3c4fbc36c7b56e1bea0a1303
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166764"
---
# <a name="method-attributes"></a>Atributos de método

Os atributos a seguir se aplicam aos métodos em uma classe, coclass ou interface.

|Atributo|DESCRIÇÃO|
|---------------|-----------------|
|[bindable](bindable.md)|Indica que a propriedade dá suporte à associação de dados.|
|[call_as](call-as.md)|Permite que uma função não Remotable seja mapeada para uma função remota.|
|[custom](custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[db_column](db-column.md)|Associa uma coluna especificada ao conjunto de linhas.|
|[db_command](db-command.md)|Cria um comando OLE DB.|
|[db_param](db-param.md)|Associa a variável de membro especificada com um parâmetro de entrada ou saída e delimita a variável.|
|[db_source](db-source.md)|Cria uma conexão com uma fonte de dados.|
|[db_table](db-table.md)|Abre uma tabela OLE DB.|
|[defaultbind](defaultbind.md)|Indica a propriedade única e vinculável que melhor representa o objeto.|
|[defaultcollelem](defaultcollelem.md)|Usado para Visual Basic otimização de código.|
|[displaybind](displaybind.md)|Indica uma propriedade que deve ser exibida para o usuário como vinculável.|
|[helpcontext](helpcontext.md)|Especifica uma ID de contexto que permite ao usuário exibir informações sobre esse elemento no arquivo de **ajuda** .|
|[helpfile](helpfile.md)|Define o nome do arquivo de **ajuda** para uma biblioteca de tipos.|
|[helpstring](helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|
|[helpstringcontext](helpstringcontext.md)|Especifica a ID de um tópico da ajuda em um arquivo. hlp ou. chm.|
|[helpstringdll](helpstringdll.md)|Especifica o nome da DLL a ser usada para executar a pesquisa de cadeia de caracteres do documento (localização).|
|[hidden](hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[id](id.md)|Especifica um DISPID para uma função membro (uma propriedade ou um método, em uma interface ou Dispinterface).|
|[immediatebind](immediatebind.md)|Indica que o banco de dados será notificado imediatamente de todas as alterações a uma propriedade de um objeto associado a um dado.|
|[Em](in-cpp.md)|Indica que um parâmetro deve ser passado do procedimento de chamada para o procedimento chamado.|
|[local](local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface. Quando usado em uma função individual, o designa um procedimento local para o qual nenhum stub é gerado.|
|[nonbrowsable](nonbrowsable.md)|Indica que um membro de interface não deve ser exibido em um navegador de propriedades.|
|[propget](propget.md)|Especifica uma função de acessador de propriedade.|
|[propput](propput.md)|Especifica uma função de configuração de propriedade.|
|[propputref](propputref.md)|Especifica uma função de configuração de propriedade que usa uma referência em vez de um valor.|
|[ptr](ptr.md)|Designa um ponteiro como um ponteiro completo.|
|[range](range-cpp.md)|Especifica um intervalo de valores permitidos para argumentos ou campos cujos valores são definidos em tempo de execução.|
|[requestedit](requestedit.md)|Indica que a propriedade dá suporte à notificação `OnRequestEdit`.|
|[restricted](restricted.md)|Especifica que um membro de um módulo, interface ou Dispinterface não pode ser chamado arbitrariamente.|
|[satype](satype.md)|Especifica o tipo de dados da estrutura de `SAFEARRAY`.|
|[origem](source-cpp.md)|Especifica as interfaces de origem do controle para pontos de conexão em uma classe. Em uma propriedade ou método, o atributo `source` indica que o membro retorna um objeto ou uma variante que é uma fonte de eventos.|
|[synchronize](synchronize.md)|Sincroniza o acesso ao método de destino.|
|[vararg](vararg.md)|Especifica que a função assume um número variável de argumentos.|

## <a name="see-also"></a>Confira também

[Atributos por uso](attributes-by-usage.md)
