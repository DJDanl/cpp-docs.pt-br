---
title: "Typedef, Enum, Union, and Struct Attributes | Microsoft Docs"
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
  - "union attributes"
  - "attributes [C++], reference topics"
  - "struct attributes"
  - "typedef attributes"
  - "enum attributes"
ms.assetid: f8a4fe94-dc02-4aed-bc31-3e500d42f4c7
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Typedef, Enum, Union, and Struct Attributes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os atributos a seguir aplicam\-se para o  [typedef](http://msdn.microsoft.com/pt-br/cc96cf26-ba93-4179-951e-695d1f5fdcf1),  [struct](../cpp/struct-cpp.md), e  [enum](../cpp/enumerations-cpp.md) palavras\-chave C\+\+.  
  
### TypeDef  
  
|Atributo|Descrição|  
|--------------|---------------|  
|[Caso](../windows/case-cpp.md)|Usado com o  [switch\_type](../windows/switch-type.md) o atributo em um  **união**.|  
|[personalizado](../windows/custom-cpp.md)|Permite definir o seu próprio atributo.|  
|[Exportar](../windows/export.md)|Faz com que uma estrutura de dados sejam colocados no arquivo. idl.|  
|[first\_is](../windows/first-is.md)|Especifica o índice do primeiro elemento da matriz para serem transmitidos.|  
|[HelpContext](../windows/helpcontext.md)|Especifica uma identificação de contexto que permite que as informações de modo de exibição do usuário sobre este elemento no arquivo de Ajuda.|  
|[arquivo de ajuda](../Topic/helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|  
|[HelpString](../windows/helpstring.md)|Especifica a string que é usada para descrever o elemento a que se aplica.|  
|[library\_block](../windows/library-block.md)|Coloca uma construção de bloco de biblioteca do arquivo. idl.|  
|[PTR](../windows/ptr.md)|Designa um ponteiro como um ponteiro completo.|  
|[Público](../windows/public-cpp-attributes.md)|Garante que um typedef irá para a biblioteca de tipo, mesmo que não é referenciado no dentro do arquivo. idl.|  
|[Ref](../windows/ref-cpp.md)|Identifica um ponteiro de referência.|  
|[switch\_is](../windows/switch-is.md)|Especifica a expressão ou um identificador que atua como o discriminant de união que seleciona o membro da união.|  
|[switch\_type](../windows/switch-type.md)|Identifica o tipo da variável usado como o discriminant de união.|  
|[exclusivo](../windows/unique-cpp.md)|Especifica um indicador único.|  
|[wire\_marshal](../windows/wire-marshal.md)|Especifica um tipo de dados que será usado para transmissão em vez de um tipo de dados específicos do aplicativo.|  
  
### Enum  
  
|Atributo|Descrição|  
|--------------|---------------|  
|[personalizado](../windows/custom-cpp.md)|Permite definir o seu próprio atributo.|  
|[Exportar](../windows/export.md)|Faz com que uma estrutura de dados sejam colocados no arquivo. idl.|  
|[UUID](../windows/uuid-cpp-attributes.md)|Especifica a identificação exclusiva de uma classe ou interface.|  
|[v1\_enum](../windows/v1-enum.md)|Dirige\-se de que o tipo enumerado especificado ser transmitidas como uma entidade de 32 bits, em vez do padrão de 16 bits.|  
  
### União  
  
|Atributo|Descrição|  
|--------------|---------------|  
|[personalizado](../windows/custom-cpp.md)|Permite definir o seu próprio atributo.|  
|[Exportar](../windows/export.md)|Faz com que uma estrutura de dados sejam colocados no arquivo. idl.|  
|[first\_is](../windows/first-is.md)|Especifica o índice do primeiro elemento da matriz para serem transmitidos.|  
|[last\_is](../windows/last-is.md)|Especifica o índice do último elemento de matriz para serem transmitidos.|  
|[length\_is](../windows/length-is.md)|Especifica o número de elementos da matriz para serem transmitidos.|  
|[max\_is](../windows/max-is.md)|Designa o valor máximo para um índice de matriz válido.|  
|[size\_is](../Topic/size_is.md)|Especifica o tamanho da memória alocada para ponteiros de tamanho, em tamanho de ponteiros para ponteiros de tamanho e único ou matrizes multidimensionais.|  
|[exclusivo](../windows/unique-cpp.md)|Especifica um indicador único.|  
|[UUID](../windows/uuid-cpp-attributes.md)|Especifica a identificação exclusiva de uma classe ou interface.|  
  
### União de nonencapsulated  
  
|Atributo|Descrição|  
|--------------|---------------|  
|[ms\_union](../windows/ms-union.md)|Controla o alinhamento de representação de dados de rede de uniões nonencapsulated.|  
|[no\_injected\_text](../windows/no-injected-text.md)|Impede que o compilador de injeção de código como resultado do uso do atributo.|  
  
### struct  
  
|Atributo|Descrição|  
|--------------|---------------|  
|[agregável](../Topic/aggregatable.md)|Indica que a classe oferece suporte à agregação.|  
|[agregações](../windows/aggregates.md)|Indica que um controle agrega a classe de destino.|  
|[appobject](../Topic/appobject.md)|Identifica o coclass como um objeto de aplicativo, que é associado a um aplicativo. exe completo e indica que as funções e propriedades do coclass estão disponíveis globalmente nesta biblioteca de tipo.|  
|[coclass](../windows/coclass.md)|Cria um controle ActiveX.|  
|[com\_interface\_entry](../Topic/com_interface_entry%20\(C++\).md)|Adiciona uma entrada de interface a um mapa de COM.|  
|[controle](../windows/control.md)|Especifica que o tipo definido pelo usuário é um controle.|  
|[personalizado](../windows/custom-cpp.md)|Permite definir o seu próprio atributo.|  
|[db\_column](../windows/db-column.md)|Vincula uma coluna especificada para o conjunto de linhas.|  
|[db\_command](../windows/db-command.md)|Cria um comando OLE DB.|  
|[db\_param](../windows/db-param.md)|Associa a variável de membro especificada com um parâmetro de entrada ou de saída e delimita a variável.|  
|[db\_source](../windows/db-source.md)|Cria a conexão com a fonte de dados.|  
|[db\_table](../windows/db-table.md)|Abre uma tabela OLE DB.|  
|[Padrão](../windows/default-cpp.md)|Indica que o personalizado ou um dispinterface definido dentro de um coclass representa a interface de programação padrão.|  
|[defaultvtable](../windows/defaultvtable.md)|Define uma interface como interface padrão vtable para um controle.|  
|[event\_receiver](../windows/event-receiver.md)|Cria um receptor de eventos.|  
|[EVENT\_SOURCE](../windows/event-source.md)|Cria uma fonte de evento.|  
|[Exportar](../windows/export.md)|Faz com que uma estrutura de dados sejam colocados no arquivo. idl.|  
|[first\_is](../windows/first-is.md)|Especifica o índice do primeiro elemento da matriz para serem transmitidos.|  
|[oculto](../Topic/hidden.md)|Indica que o item existe mas não deve ser exibido em um navegador orientado a usuário.|  
|[implements\_category](../Topic/implements_category.md)|Especifica as categorias de componente implementada para a classe.|  
|[last\_is](../windows/last-is.md)|Especifica o índice do último elemento de matriz para serem transmitidos.|  
|[length\_is](../windows/length-is.md)|Especifica o número de elementos da matriz para serem transmitidos.|  
|[max\_is](../windows/max-is.md)|Designa o valor máximo para um índice de matriz válido.|  
|[requires\_category](../windows/requires-category.md)|Especifica as categorias de componente necessário da classe destino.|  
|[size\_is](../Topic/size_is.md)|Especifica o tamanho da memória alocada para ponteiros de tamanho, em tamanho de ponteiros para ponteiros de tamanho e único ou matrizes multidimensionais.|  
|[fonte](../Topic/source%20\(C++\).md)|Em uma classe, especifica as interfaces de origem do objeto COM para pontos de conexão.  Em uma propriedade ou método, indica que o membro retorna um objeto ou uma VARIANTE que é uma fonte de eventos.|  
|[Threading](../windows/threading-cpp.md)|Especifica o modelo de segmentação para um objeto COM.|  
|[exclusivo](../windows/unique-cpp.md)|Especifica um indicador único.|  
|[UUID](../windows/uuid-cpp-attributes.md)|Especifica a identificação exclusiva de uma classe ou interface.|  
|[version](../windows/version-cpp.md)|Identifica uma versão específica entre várias versões de uma classe.|  
|[vi\_progid](../windows/vi-progid.md)|Especifica um formulário independente de versão de ProgID.|  
  
## Consulte também  
 [Attributes by Usage](../windows/attributes-by-usage.md)