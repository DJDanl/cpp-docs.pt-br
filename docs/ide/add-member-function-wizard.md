---
title: Assistente de Adição de Função de Membro
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.function.overview
helpviewer_keywords:
- Add Member Function Wizard [C++]
ms.assetid: 13b6defc-faa6-4d57-83db-9dd854cbea3d
ms.openlocfilehash: 6ba95026d712c71a9d706baddfefda548100c64a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50615040"
---
# <a name="add-member-function-wizard"></a>Assistente de Adição de Função de Membro

Este assistente adiciona uma declaração da função de membro ao arquivo de cabeçalho e uma implementação de função de membro de stub ao arquivo de implementação da classe selecionada.

Depois de adicionar a função de membro usando o assistente, edite o código no ambiente de desenvolvimento.

- **Tipo de retorno**

   Define o tipo de retorno da função de membro que está sendo adicionada. Forneça seu próprio tipo de retorno ou selecione um na lista de tipos disponíveis. Para obter informações sobre os tipos, confira [Tipos fundamentais](../cpp/fundamental-types-cpp.md).

   ||||
   |-|-|-|
   |**char**|**int**|**unsigned int**|
   |**double**|**long**|**unsigned long**|
   |**float**|**short**|**void**|
   |`HRESULT`|**unsigned char**||

- **Nome da função**

   Define o nome da função de membro que está sendo adicionada.

- **Tipo de parâmetro**

   Define o tipo de parâmetro que está sendo adicionado à função de membro, caso a função de membro tenha parâmetros. Forneça seu próprio tipo de parâmetro ou selecione um na lista de tipos disponíveis.

   ||||
   |-|-|-|
   |**char**|**int**|**unsigned char**|
   |**double**|**long**|**unsigned int**|
   |**float**|**short**|**unsigned long**|

- **Nome do parâmetro**

   Define o nome de um parâmetro que está sendo adicionado à função de membro, caso a função de membro tenha parâmetros.

- **Lista de parâmetros**

   Exibe uma lista de parâmetros adicionados à função de membro. Para adicionar um parâmetro à lista, forneça um tipo e um nome nas caixas **Tipo de parâmetro** e **Nome do parâmetro** e clique em **Adicionar**. Para remover um parâmetro da lista, selecione o parâmetro e clique em **Remover**.

- **Access**

   Define o acesso à função de membro. Modificadores de acesso são palavras-chave que especificam o acesso que outras classes têm à função de membro. Confira [Controle de acesso a membro](../cpp/member-access-control-cpp.md) para obter mais informações sobre como especificar o acesso. O nível de acesso da função de membro é definido como **public** por padrão.

   - [public](../cpp/public-cpp.md)

   - [protected](../cpp/protected-cpp.md)

   - [private](../cpp/private-cpp.md)

   Verifique se a nova função de membro é estática ou virtual, e se ela é embutida ou pura. Se você definir a função de membro para que ela seja pura, a caixa de seleção `Virtual` será marcada e a caixa de seleção **Embutida** não ficará disponível. O padrão é uma função de membro não estática e não virtual.

   |Opção|Descrição|
   |------------|-----------------|
   |[Estático](../cpp/storage-classes-cpp.md)|Especifica que a função atua como uma função global e pode ser chamada fora da classe, mesmo sem nenhuma instanciação de classe. A função de membro não tem acesso a membros não estáticos. Uma função de membro especificada como `Static` não pode ser virtual.|
   |[Virtual](../cpp/virtual-cpp.md)|Garante que a função de membro correta seja chamada para um objeto, seja qual for a expressão usada para fazer a chamada à função de membro. Uma função de membro especificada como `Virtual` não pode ser estática.|
   |**Pura**|Indica que nenhuma implementação é fornecida para a função de membro virtual que está sendo declarada; portanto, a opção **Pura** pode ser especificada somente em funções de membro virtuais. Uma classe que contém, pelo menos, uma função de membro virtual pura é considerada uma classe abstrata. Classes derivadas da classe abstrata precisam implementar a função de membro virtual pura, ou também serão classes abstratas.|
   |[Embutida](../cpp/inline-functions-cpp.md)|Instrui o compilador a inserir uma cópia do corpo da função de membro em cada local em que a função de membro é chamada. Uma função de membro especificada como **Embutida** não pode ser pura.|

- **Arquivo .cpp**

   Define o local de arquivo em que a implementação da função de membro de stub é gravada. Por padrão, ela é gravada no arquivo .cpp da classe à qual a função de membro é adicionada. Clique no botão de reticências para alterar o nome do arquivo. A implementação da função de membro é adicionada ao conteúdo do arquivo selecionado.

- **Comentário**

   Fornece um comentário no arquivo de cabeçalho da função de membro.

- **Assinatura de função**

   Exibe a função de membro como ela aparece no código quando você clica em **Concluir**. Não possível editar o texto dessa caixa. Para alterar a função de membro, altere as caixas apropriadas no assistente.

## <a name="see-also"></a>Consulte também

[Adicionando uma função de membro](../ide/adding-a-member-function-visual-cpp.md)