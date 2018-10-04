---
title: Atributos de método (COM C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- method attributes
- attributes [C++/CLI], reference topics
ms.assetid: b2313352-480d-488b-8c35-6242ffd3a549
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8f5f9af9e302b9346b2bd42acdf1e268a59113f7
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790128"
---
# <a name="method-attributes"></a>Atributos de método

Os atributos a seguir se aplicam aos métodos em uma classe, coclass ou interface.

|Atributo|Descrição|
|---------------|-----------------|
|[bindable](bindable.md)|Indica que a propriedade dá suporte à associação de dados.|
|[call_as](call-as.md)|Permite que uma função nonremotable a ser mapeada para uma função remota.|
|[custom](custom-cpp.md)|Permite que você defina seu próprio atributo.|
|[db_column](db-column.md)|Associa uma coluna especificada para o conjunto de linhas.|
|[db_command](db-command.md)|Cria um comando OLE DB.|
|[db_param](db-param.md)|Associa a variável de membro especificado com um parâmetro de entrada ou saído e delimita a variável.|
|[db_source](db-source.md)|Cria uma conexão a uma fonte de dados.|
|[db_table](db-table.md)|Abre uma tabela de OLE DB.|
|[defaultbind](defaultbind.md)|Indica a única propriedade associável que melhor representa o objeto.|
|[defaultcollelem](defaultcollelem.md)|Usada para otimização de código do Visual Basic.|
|[displaybind](displaybind.md)|Indica uma propriedade que deve ser exibida para o usuário como associável.|
|[helpcontext](helpcontext.md)|Especifica uma ID de contexto que permite que usuários exibir informações sobre este elemento na **ajudar** arquivo.|
|[helpfile](helpfile.md)|Define o nome da **ajudar** arquivo para uma biblioteca de tipos.|
|[helpstring](helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|
|[helpstringcontext](helpstringcontext.md)|Especifica a ID do tópico da Ajuda em um arquivo. hlp ou. chm.|
|[helpstringdll](helpstringdll.md)|Especifica o nome da DLL a usar para executar a pesquisa de cadeia de caracteres do documento (localização).|
|[hidden](hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[id](id.md)|Especifica um DISPID para uma função de membro (uma propriedade ou um método, em uma interface ou dispinterface).|
|[immediatebind](immediatebind.md)|Indica que o banco de dados será notificado imediatamente de todas as alterações a uma propriedade de um objeto de associação de dados.|
|[in](in-cpp.md)|Indica que um parâmetro deve ser passado do procedimento de chamada para o procedimento chamado.|
|[local](local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface. Quando usado em uma função individual, designa um procedimento de local para o qual nenhuma stubs são gerados.|
|[nonbrowsable](nonbrowsable.md)|Indica que um membro de interface não deve ser exibido em um navegador de propriedade.|
|[propget](propget.md)|Especifica uma função de acessador de propriedade.|
|[propput](propput.md)|Especifica uma função de configuração de propriedade.|
|[propputref](propputref.md)|Especifica uma função de configuração de propriedade que usa uma referência em vez de um valor.|
|[ptr](ptr.md)|Designa um ponteiro como um ponteiro completo.|
|[range](range-cpp.md)|Especifica um intervalo de valores permitidos para argumentos ou campos cujos valores são definidos em tempo de execução.|
|[requestedit](requestedit.md)|Indica que a propriedade oferece suporte a `OnRequestEdit` notificação.|
|[restricted](restricted.md)|Especifica que um membro de um módulo, interface ou dispinterface não pode ser chamado arbitrariamente.|
|[satype](satype.md)|Especifica o tipo de dados a `SAFEARRAY` estrutura.|
|[source](source-cpp.md)|Especifica as interfaces de origem do controle para pontos de conexão em uma classe. Em uma propriedade ou método, o `source` atributo indica que o membro retorna um objeto ou uma VARIANTE que é uma origem de eventos.|
|[synchronize](synchronize.md)|Sincroniza o acesso ao método de destino.|
|[vararg](vararg.md)|Especifica que a função tem um número variável de argumentos.|

## <a name="see-also"></a>Consulte também

[Atributos por uso](attributes-by-usage.md)