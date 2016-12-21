---
title: "Assistente de Adi&#231;&#227;o de Fun&#231;&#227;o de Membro | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.codewiz.function.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de Adição de Função de Membro [C++]"
ms.assetid: 13b6defc-faa6-4d57-83db-9dd854cbea3d
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente de Adi&#231;&#227;o de Fun&#231;&#227;o de Membro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este assistente adiciona uma declaração de função de membro para o arquivo de cabeçalho e uma implementação de função de membro de stub para o arquivo de implementação para a classe selecionada.  
  
 Depois de adicionar a função de membro usando o assistente, você pode editar o código no ambiente de desenvolvimento.  
  
 **Tipo de retorno**  
 Define o tipo de retorno da função de membro que você está adicionando.  Você pode fornecer seu próprio tipo de retorno, ou você pode selecionar da lista de tipos disponíveis.  Para obter informações sobre os tipos, consulte  [Tipos fundamentais](../cpp/fundamental-types-cpp.md).  
  
||||  
|-|-|-|  
|`char`|`int`|`unsigned int`|  
|**double**|**long**|`unsigned long`|  
|**float**|**short**|`void`|  
|`HRESULT`|`unsigned char`||  
  
 **Nome da função**  
 Define o nome da função de membro que você está adicionando.  
  
 **Tipo de parâmetro**  
 Define o tipo do parâmetro que você está adicionando para a função de membro, se a função de membro tiver parâmetros.  Você pode fornecer seu próprio tipo de parâmetro, ou você pode selecionar da lista de tipos disponíveis.  
  
||||  
|-|-|-|  
|`char`|`int`|`unsigned char`|  
|**double**|**long**|`unsigned int`|  
|**float**|**short**|`unsigned long`|  
  
 **Nome do parâmetro**  
 Define o nome de um parâmetro que você está adicionando para a função de membro, se a função de membro tiver parâmetros.  
  
 **Lista de parâmetros**  
 Exibe uma lista de parâmetros que você adicionou à função de membro.  Para adicionar um parâmetro à lista, forneça um tipo e nome na  **tipo de parâmetro** e  **o nome do parâmetro** caixas e clique em  **Add**.  Para remover um parâmetro na lista, selecione o parâmetro e clique em  **Remover**.  
  
 **Access**  
 Define o acesso à função de membro.  Modificadores de acesso são as palavras\-chave que especificam o acesso a que outras classes têm à função de membro.  Consulte  [O controle de acesso de membro](../cpp/member-access-control-cpp.md) para obter mais informações sobre como especificar o acesso.  O nível de acesso da função de membro é definido como  **pública** por padrão.  
  
-   [Público](../cpp/public-cpp.md)  
  
-   [Protegido](../Topic/protected%20\(C++\).md)  
  
-   [Particular](../Topic/private%20\(C++\).md)  
  
 Verifique se a nova função de membro é estático ou virtual e se ela está embutida ou puro.  Se você definir a função de membro ser puro, o `Virtual` caixa de seleção estiver marcada e o  **in\-line** caixa de seleção ficará indisponível.  O padrão é uma função de membro não estática, nonvirtual.  
  
|Opção|Descrição|  
|-----------|---------------|  
|[Estático](../misc/static-cpp.md)|Especifica que a função atua como um global e pode ser chamada fora da classe, mesmo com nenhuma instanciação de classe.  A função de membro não tem acesso aos membros não\-static.  Uma função de membro especificada como `Static` não pode ser virtual.|  
|[Virtual](../cpp/virtual-cpp.md)|Garante que a função de membro correto é chamada de um objeto, independentemente da expressão usada para fazer com que a função de membro chamada.  Uma função de membro especificada como `Virtual` não pode ser estático.|  
|**Puro**|Indica que nenhuma implementação é fornecida para a função de membro virtual que está sendo declarada; Portanto,  **puro** pode ser especificado somente em funções de membro virtual.  Consulte  [Sintaxe de declaração de membro da classe](../Topic/Class-Member%20Declaration%20Syntax.md) para obter mais informações.<br /><br /> Uma classe que contém pelo menos uma função de membro virtual pura é considerada uma classe abstrata.  Classes derivadas da classe abstrata devem implementar a função de membro virtual puro ou, também, são classes abstratas.|  
|[Interno](../Topic/Inline%20Functions%20\(C++\).md)|Instrui o compilador para inserir uma cópia do corpo da função de membro em cada local em que a função de membro é chamada.  Uma função de membro especificada como  **in\-line** não pode ser puro.|  
  
 **arquivo. cpp**  
 Define o local do arquivo onde a implementação de função de membro de stub é gravada.  Por padrão, ele é escrito no arquivo. cpp para a classe à qual a função de membro é adicionada.  Clique no botão de reticências para alterar o nome do arquivo.  A implementação da função de membro é adicionada ao conteúdo do arquivo selecionado.  
  
 **Comment**  
 Fornece um comentário no arquivo de cabeçalho para a função de membro.  
  
 **Assinatura de função**  
 Exibe a função de membro, como ele aparece no código quando você clica em  **Concluir**.  Você não pode editar o texto dessa caixa.  Para alterar a função de membro, altere as caixas apropriadas no assistente.  
  
## Consulte também  
 [Adicionando uma função de membro](../ide/adding-a-member-function-visual-cpp.md)