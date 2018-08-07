---
title: Atributos de método | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- method attributes
- attributes [C++], reference topics
ms.assetid: b2313352-480d-488b-8c35-6242ffd3a549
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1850507b9d00ab717a2602d4e230968f5222f077
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39604275"
---
# <a name="method-attributes"></a>Atributos de método
Os atributos a seguir se aplicam aos métodos em uma classe, coclass ou interface.  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|[bindable](../windows/bindable.md)|Indica que a propriedade dá suporte à associação de dados.|  
|[call_as](../windows/call-as.md)|Permite que uma função nonremotable a ser mapeada para uma função remota.|  
|[custom](../windows/custom-cpp.md)|Permite que você defina seu próprio atributo.|  
|[db_column](../windows/db-column.md)|Associa uma coluna especificada para o conjunto de linhas.|  
|[db_command](../windows/db-command.md)|Cria um comando OLE DB.|  
|[db_param](../windows/db-param.md)|Associa a variável de membro especificado com um parâmetro de entrada ou saído e delimita a variável.|  
|[db_source](../windows/db-source.md)|Cria uma conexão a uma fonte de dados.|  
|[db_table](../windows/db-table.md)|Abre uma tabela de OLE DB.|  
|[defaultbind](../windows/defaultbind.md)|Indica a única propriedade associável que melhor representa o objeto.|  
|[defaultcollelem](../windows/defaultcollelem.md)|Usada para otimização de código do Visual Basic.|  
|[displaybind](../windows/displaybind.md)|Indica uma propriedade que deve ser exibida para o usuário como associável.|  
|[helpcontext](../windows/helpcontext.md)|Especifica uma ID de contexto que permite que usuários exibir informações sobre esse elemento no arquivo de Ajuda.|  
|[helpfile](../windows/helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|  
|[helpstring](../windows/helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|  
|[helpstringcontext](../windows/helpstringcontext.md)|Especifica a ID do tópico da Ajuda em um arquivo. hlp ou. chm.|  
|[helpstringdll](../windows/helpstringdll.md)|Especifica o nome da DLL a usar para executar a pesquisa de cadeia de caracteres do documento (localização).|  
|[hidden](../windows/hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|  
|[id](../windows/id.md)|Especifica um DISPID para uma função de membro (uma propriedade ou um método, em uma interface ou dispinterface).|  
|[immediatebind](../windows/immediatebind.md)|Indica que o banco de dados será notificado imediatamente de todas as alterações a uma propriedade de um objeto de associação de dados.|  
|[in](../windows/in-cpp.md)|Indica que um parâmetro deve ser passado do procedimento de chamada para o procedimento chamado.|  
|[local](../windows/local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface. Quando usado em uma função individual, designa um procedimento de local para o qual nenhuma stubs são gerados.|  
|[nonbrowsable](../windows/nonbrowsable.md)|Indica que um membro de interface não deve ser exibido em um navegador de propriedade.|  
|[propget](../windows/propget.md)|Especifica uma função de acessador de propriedade.|  
|[propput](../windows/propput.md)|Especifica uma função de configuração de propriedade.|  
|[propputref](../windows/propputref.md)|Especifica uma função de configuração de propriedade que usa uma referência em vez de um valor.|  
|[ptr](../windows/ptr.md)|Designa um ponteiro como um ponteiro completo.|  
|[range](../windows/range-cpp.md)|Especifica um intervalo de valores permitidos para argumentos ou campos cujos valores são definidos em tempo de execução.|  
|[requestedit](../windows/requestedit.md)|Indica que a propriedade oferece suporte a `OnRequestEdit` notificação.|  
|[restricted](../windows/restricted.md)|Especifica que um membro de um módulo, interface ou dispinterface não pode ser chamado arbitrariamente.|  
|[satype](../windows/satype.md)|Especifica o tipo de dados a `SAFEARRAY` estrutura.|  
|[source](../windows/source-cpp.md)|Especifica as interfaces de origem do controle para pontos de conexão em uma classe. Em uma propriedade ou método, o `source` atributo indica que o membro retorna um objeto ou uma VARIANTE que é uma origem de eventos.|  
|[synchronize](../windows/synchronize.md)|Sincroniza o acesso ao método de destino.|  
|[vararg](../windows/vararg.md)|Especifica que a função tem um número variável de argumentos.|  
  
## <a name="see-also"></a>Consulte também  
 [Atributos por uso](../windows/attributes-by-usage.md)