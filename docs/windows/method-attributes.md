---
title: "Method Attributes | Microsoft Docs"
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
  - "method attributes"
  - "attributes [C++], reference topics"
ms.assetid: b2313352-480d-488b-8c35-6242ffd3a549
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Method Attributes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os atributos a seguir se aplicam aos métodos em uma classe, coclass ou interface.  
  
|Atributo|Descrição|  
|--------------|---------------|  
|[ligáveis](../windows/bindable.md)|Indica que a propriedade oferece suporte a vinculação de dados.|  
|[call\_as](../windows/call-as.md)|Permite que uma função não remota seja mapeada para uma função remota.|  
|[personalizado](../windows/custom-cpp.md)|Permite definir o seu próprio atributo.|  
|[db\_column](../windows/db-column.md)|Vincula uma coluna especificada para o conjunto de linhas.|  
|[db\_command](../windows/db-command.md)|Cria um comando OLE DB.|  
|[db\_param](../windows/db-param.md)|Associa a variável de membro especificada com um parâmetro de entrada ou de saída e delimita a variável.|  
|[db\_source](../windows/db-source.md)|Cria a conexão com a fonte de dados.|  
|[db\_table](../windows/db-table.md)|Abre uma tabela OLE DB.|  
|[defaultbind](../windows/defaultbind.md)|Indica a propriedade única e vinculável que melhor representa o objeto.|  
|[defaultcollelem](../windows/defaultcollelem.md)|Usado para otimização de código Visual Basic.|  
|[displaybind](../windows/displaybind.md)|Indica uma propriedade que deve ser exibida ao usuário como bindable.|  
|[HelpContext](../windows/helpcontext.md)|Especifica uma identificação de contexto que permite que as informações de modo de exibição do usuário sobre este elemento no arquivo de Ajuda.|  
|[arquivo de ajuda](../Topic/helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|  
|[HelpString](../windows/helpstring.md)|Especifica a string que é usada para descrever o elemento a que se aplica.|  
|[helpstringcontext](../windows/helpstringcontext.md)|Especifica a ID de um tópico da ajuda em um arquivo .hlp ou .chm.|  
|[helpstringdll](../windows/helpstringdll.md)|Especifica o nome da DLL a ser usada para executar a pesquisa de  string no documento \(localização\).|  
|[oculto](../Topic/hidden.md)|Indica que o item existe mas não deve ser exibido em um navegador orientado a usuário.|  
|[id](../windows/id.md)|Especifica um DISPID para uma função membro \(uma propriedade ou um método, em uma interface ou dispinterface\).|  
|[immediatebind](../windows/immediatebind.md)|Indica que o banco de dados será notificado imediatamente de todas as alterações a uma propriedade de um objeto de dados vinculado.|  
|[Em](../Topic/in%20\(C++\).md)|Indica que é um parâmetro a ser passado do procedimento de chamada para o procedimento chamado.|  
|[local](../windows/local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface.  Quando usado em uma função individual, designa um procedimento de local para o qual nenhum fragmento de código é gerados.|  
|[nonbrowsable](../Topic/nonbrowsable.md)|Indica que um membro da interface não deve ser exibido em um navegador de propriedade.|  
|[propget](../windows/propget.md)|Especifica uma função de assessor de propriedade.|  
|[propput](../windows/propput.md)|Especifica uma função de configuração da propriedade.|  
|[propputref](../windows/propputref.md)|Especifica uma função de configuração da propriedade que usa uma referência em vez de um valor.|  
|[PTR](../windows/ptr.md)|Designa um ponteiro como um ponteiro completo.|  
|[intervalo](../Topic/range%20\(C++\).md)|Especifica um intervalo de valores permitidos para os argumentos ou campos cujos valores são definidos em tempo de execução.|  
|[requestedit](../windows/requestedit.md)|Indica que a propriedade oferece suporte a  **OnRequestEdit** notificação.|  
|[restrito](../windows/restricted.md)|Especifica que um membro de um módulo, interface ou dispinterface não pode ser chamado arbitrariamente.|  
|[satype](../windows/satype.md)|Especifica o tipo de dados da  **SAFEARRAY** estrutura.|  
|[fonte](../Topic/source%20\(C++\).md)|Especifica as interfaces de origem do controle para pontos de conexão em uma classe.  Em uma propriedade ou método, o  **origem**  atributo indica que o membro retorna um objeto ou uma VARIANTE que é uma fonte de eventos.|  
|[sincronizar](../windows/synchronize.md)|Sincroniza o acesso para o método de destino.|  
|[vararg](../windows/vararg.md)|Especifica que a função levar um número variável de argumentos.|  
  
## Consulte também  
 [Attributes by Usage](../windows/attributes-by-usage.md)