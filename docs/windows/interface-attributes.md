---
title: "Interface Attributes | Microsoft Docs"
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
  - "attributes [C++], reference topics"
  - "interface attributes"
ms.assetid: 27fcdfee-abce-4585-8b53-ee31635356e8
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interface Attributes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os atributos a seguir aplicam\-se para o  [interface \(ou \_\_interface\)](../Topic/__interface.md) palavra\-chave do C\+\+.  
  
|Atributo|Descrição|  
|--------------|---------------|  
|[async\_uuid](../Topic/async_uuid.md)|Especifica o UUID que instrui o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.|  
|[personalizado](../windows/custom-cpp.md)|Permite definir seus próprios atributos.|  
|[dispinterface](../windows/dispinterface.md)|Coloca uma interface no arquivo. idl como uma interface de despacho.|  
|[dual](../Topic/dual.md)|Coloca uma interface no arquivo. idl como uma interface dupla.|  
|[Exportar](../windows/export.md)|Faz com que uma estrutura de dados sejam colocados no arquivo. idl.|  
|[HelpContext](../windows/helpcontext.md)|Especifica uma identificação de contexto que permite que as informações de modo de exibição do usuário sobre este elemento no arquivo de Ajuda.|  
|[arquivo de ajuda](../Topic/helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|  
|[HelpString](../windows/helpstring.md)|Especifica a string que é usada para descrever o elemento a que se aplica.|  
|[helpstringcontext](../windows/helpstringcontext.md)|Especifica a ID de um tópico da ajuda em um arquivo .hlp ou .chm.|  
|[helpstringdll](../windows/helpstringdll.md)|Especifica o nome da DLL a ser usada para executar a pesquisa de  string no documento \(localização\).|  
|[oculto](../Topic/hidden.md)|Indica que o item existe mas não deve ser exibido em um navegador orientado a usuário.|  
|[library\_block](../windows/library-block.md)|Coloca uma construção de bloco de biblioteca do arquivo. idl.|  
|[local](../windows/local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface.  Quando usado em uma função individual, designa um procedimento de local para o qual nenhum fragmento de código é gerados.|  
|[não](../Topic/nonextensible.md)|Especifica que o `IDispatch` a implementação inclui somente as propriedades e métodos listados na descrição da interface e não podem ser estendidos com membros adicionais em tempo de execução.  Esse atributo é válido somente em um  [dual](../Topic/dual.md) interface.|  
|[odl](../windows/odl.md)|Identifica uma interface como uma interface de linguagem de descrição de objeto \(ODL\).|  
|[object](../Topic/object%20\(C++\).md)|Identifica uma interface personalizada.|  
|[oleautomation](../windows/oleautomation.md)|Indica que uma interface é compatível com a automação.|  
|[pointer\_default](../windows/pointer-default.md)|Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto os ponteiros de nível superior que aparecem em listas de parâmetros.|  
|[PTR](../windows/ptr.md)|Designa um ponteiro como um ponteiro completo.|  
|[restrito](../windows/restricted.md)|Designa os membros da biblioteca não podem ser chamados arbitrariamente.|  
|[UUID](../windows/uuid-cpp-attributes.md)|Fornece a identificação exclusiva para a biblioteca|  
  
 Você deve observar essas regras para definição de uma interface:  
  
-   Convenção de chamada padrão é  [\_\_stdcall](../cpp/stdcall.md).  
  
-   Um GUID é fornecido para você, se você não fornecer um.  
  
-   Não há métodos sobrecarregados são permitidos.  
  
 Ao não especificar o  [uuid](../windows/uuid-cpp-attributes.md) de atributo e usando o mesmo nome de interface em projetos de atributos diferentes, o mesmo GUID é gerado.  
  
## Consulte também  
 [Attributes by Usage](../windows/attributes-by-usage.md)