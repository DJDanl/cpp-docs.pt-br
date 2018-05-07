---
title: Adicionar Assistente de função de membro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.function.overview
dev_langs:
- C++
helpviewer_keywords:
- Add Member Function Wizard [C++]
ms.assetid: 13b6defc-faa6-4d57-83db-9dd854cbea3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 488c7ca455b267a79b0d2906849596346a191792
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="add-member-function-wizard"></a>Assistente de Adição de Função de Membro
Este assistente adiciona uma declaração de função de membro para o arquivo de cabeçalho e uma implementação de função de membro de stub para o arquivo de implementação para a classe selecionada.  
  
 Depois de adicionar a função de membro usando o assistente, você pode editar o código no ambiente de desenvolvimento.  
  
 **Tipo de retorno**  
 Define o tipo de retorno da função de membro que você está adicionando. Você pode fornecer seu próprio tipo de retorno, ou você pode selecionar na lista de tipos disponíveis. Para obter informações sobre os tipos, consulte [tipos fundamentais](../cpp/fundamental-types-cpp.md).  
  
||||  
|-|-|-|  
|`char`|`int`|`unsigned int`|  
|**double**|**long**|`unsigned long`|  
|**float**|**short**|`void`|  
|`HRESULT`|`unsigned char`||  
  
 **Nome da função**  
 Define o nome da função de membro que você está adicionando.  
  
 **Tipo de parâmetro**  
 Define o tipo de parâmetro que você está adicionando para a função de membro, se a função de membro tiver parâmetros. Você pode fornecer seu próprio tipo de parâmetro, ou você pode selecionar na lista de tipos disponíveis.  
  
||||  
|-|-|-|  
|`char`|`int`|`unsigned char`|  
|**double**|**long**|`unsigned int`|  
|**float**|**short**|`unsigned long`|  
  
 **Nome do parâmetro**  
 Define o nome de um parâmetro que você está adicionando para a função de membro, se a função de membro tiver parâmetros.  
  
 **Lista de parâmetros**  
 Exibe uma lista de parâmetros que você adicionou à função de membro. Para adicionar um parâmetro à lista, forneça um tipo e nome no **tipo de parâmetro** e **nome do parâmetro** caixas e clique em **adicionar**. Para remover um parâmetro na lista, selecione o parâmetro e clique em **remover**.  
  
 **Access**  
 Define o acesso à função de membro. Modificadores de acesso são palavras-chave que especificam o outras classes de acesso à função de membro. Consulte [controle de acesso de membro](../cpp/member-access-control-cpp.md) para obter mais informações sobre como especificar o acesso. O nível de acesso da função de membro é definido como **pública** por padrão.  
  
-   [public](../cpp/public-cpp.md)  
  
-   [protected](../cpp/protected-cpp.md)  
  
-   [private](../cpp/private-cpp.md)  
  
 Verifique se a nova função de membro é estático ou virtual, e se ele é embutido ou puro. Se você definir a função de membro para ser puro, o `Virtual` caixa de seleção estiver marcada e o **embutido** caixa de seleção torna-se indisponível. O padrão é uma função de membro não estático, não virtual.  
  
|Opção|Descrição|  
|------------|-----------------|  
|[Estático](../cpp/storage-classes-cpp.md)|Especifica que a função atua como global e pode ser chamada de fora da classe, mesmo com nenhuma instanciação de classe. A função de membro não tem acesso a membros não estáticos. Uma função de membro especificada como `Static` não pode ser virtual.|  
|[Virtual](../cpp/virtual-cpp.md)|Garante que a função de membro correto é chamada de um objeto, independentemente da expressão usada para fazer com que a função de membro chamada. Uma função de membro especificada como `Virtual` não pode ser estático.|  
|**Puro**|Indica que nenhuma implementação é fornecida para a função de membro virtual que está sendo declarada; Portanto, **puro** pode ser especificada somente em funções membro virtual. Uma classe que contém pelo menos uma função de membro puramente virtual é considerada uma classe abstrata. Classes derivadas da classe abstrata devem implementar a função de membro puramente virtual ou, também são classes abstratas.|  
|[Embutido](../cpp/inline-functions-cpp.md)|Instrui o compilador para inserir uma cópia do corpo da função de membro em cada local que é chamada de função de membro. Uma função de membro especificada como **embutido** não pode ser puro.|  
  
 **arquivo. cpp**  
 Define o local do arquivo em que a implementação de função de membro de stub é gravada. Por padrão, ela é gravada no arquivo. cpp para a classe à qual a função de membro é adicionada. Clique no botão de reticências para alterar o nome do arquivo. A implementação da função de membro é adicionada ao conteúdo do arquivo selecionado.  
  
 **Comentário**  
 Fornece um comentário no arquivo de cabeçalho para a função de membro.  
  
 **Assinatura de função**  
 Exibe a função de membro como ele aparece no código, quando você clica em **concluir**. Você não pode editar o texto nesta caixa. Para alterar a função de membro, altere as caixas apropriadas no assistente.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionar uma função de membro](../ide/adding-a-member-function-visual-cpp.md)