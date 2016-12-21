---
title: "Atributos #import (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Diretiva #import, atributos"
ms.assetid: 2a5085e3-82ee-4f83-892b-0aa6cc13863b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Atributos #import (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Fornece links para atributos usados com a política \#import.  
  
 **Específico da Microsoft**  
  
 Os seguintes atributos estão disponíveis para a política \#import.  
  
|Atributo|Descrição|  
|--------------|---------------|  
|[auto\_rename](../preprocessor/auto-rename.md)|Renomeia palavras reservadas C\+\+ com dois sublinhados \(\_\_\) para o nome da variável para resolver possíveis conflitos de nome.|  
|[auto\_search](../preprocessor/auto-search.md)|Especifica que, quando uma biblioteca de tipos é referenciada com \#import e ela mesma referencia outra biblioteca de tipos, o compilador pode fazer um \#import implícito para a outra biblioteca de tipos.|  
|[embedded\_idl](../preprocessor/embedded-idl.md)|Especifica que a biblioteca de tipos é gravada no arquivo .tlh com o código gerado pelo atributo preservado.|  
|[exclude](../preprocessor/exclude-hash-import.md)|Exclui itens dos arquivos de cabeçalho da biblioteca de tipos que estão sendo gerados.|  
|[high\_method\_prefix](../preprocessor/high-method-prefix.md)|Especifica um prefixo a ser usado na nomeação de propriedades e métodos de alto nível.|  
|[high\_property\_prefixes](../Topic/high_property_prefixes.md)|Especifica prefixos alternativos para três métodos da propriedade.|  
|[implementation\_only](../preprocessor/implementation-only.md)|Suprime geração do arquivo de cabeçalho .tlh \(o arquivo de cabeçalho primário\).|  
|[include\(\)](../preprocessor/include-parens.md)|Desabilita a exclusão automática.|  
|[inject\_statement](../preprocessor/inject-statement.md)|Insere seu argumento como texto de origem no cabeçalho da biblioteca de tipos.|  
|[named\_guids](../preprocessor/named-guids.md)|Diz para o compilador definir e inicializar variáveis GUID no estilo antigo, na forma **LIBID\_MyLib**, **CLSID\_MyCoClass**, **IID\_MyInterface** e **DIID\_MyDispInterface**.|  
|[no\_auto\_exclude](../preprocessor/no-auto-exclude.md)|Desabilita a exclusão automática.|  
|[no\_dual\_interfaces](../preprocessor/no-dual-interfaces.md)|Altera o modo como o compilador gerenciar funções wrapper para métodos da interface dupla.|  
|[no\_implementation](../preprocessor/no-implementation.md)|Suprime geração do cabeçalho .tli, que contém as implementações das funções de membro do wrapper.|  
|[no\_namespace](../Topic/no_namespace.md)|Especifica que o nome do namespace não é gerado pelo compilador.|  
|[no\_registry](../Topic/no_registry.md)|Diz para o compilador não procurar no Registro por bibliotecas de tipos.|  
|[no\_search\_namespace](../preprocessor/no-search-namespace.md)|Tem a mesma funcionalidade do atributo [no\_namespace](../Topic/no_namespace.md), mas é usado em bibliotecas de tipos que você usa a política \#import com o atributo [auto\_search](../preprocessor/auto-search.md).|  
|[no\_smart\_pointers](../preprocessor/no-smart-pointers.md)|Suprime a criação de ponteiros inteligentes para todas as interfaces na biblioteca de tipos.|  
|[raw\_dispinterfaces](../Topic/raw_dispinterfaces.md)|Diz para o compilador gerar funções wrapper de nível baixo para os métodos e as propriedades dispinterface que chamam **IDispatch::Invoke** e retornam o código de erro `HRESULT`.|  
|[raw\_interfaces\_only](../Topic/raw_interfaces_only.md)|Suprime geração de funções wrapper de tratamento de erros e declarações [propriedade](../cpp/property-cpp.md) que usam essas funções wrapper.|  
|[raw\_method\_prefix](../preprocessor/raw-method-prefix.md)|Especifica um prefixo diferente para evitar colisões de nome.|  
|[raw\_native\_types](../Topic/raw_native_types.md)|Desabilita o uso de classes de suporte COM nas funções wrapper de alto nível e força o uso de tipos de dados de nível baixo.|  
|[raw\_property\_prefixes](../preprocessor/raw-property-prefixes.md)|Especifica prefixos alternativos para três métodos da propriedade.|  
|[rename](../preprocessor/rename-hash-import.md)|Soluciona os problemas de colisão de nome.|  
|[rename\_namespace](../preprocessor/rename-namespace.md)|Renomeia o namespace que contém o conteúdo da biblioteca de tipos.|  
|[rename\_search\_namespace](../preprocessor/rename-search-namespace.md)|Tem a mesma funcionalidade do atributo [rename\_namespace](../preprocessor/rename-namespace.md), mas é usado em bibliotecas de tipos que você usa a política \#import com o atributo [auto\_search](../preprocessor/auto-search.md).|  
|[tlbid](../preprocessor/tlbid.md)|Permite carregar bibliotecas diferentes de biblioteca de tipos primárias.|  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md)