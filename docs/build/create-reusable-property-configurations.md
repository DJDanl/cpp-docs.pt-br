---
title: Compartilhar ou reutilizar as configurações do projeto Do Visual Studio - C++
ms.date: 07/17/2019
helpviewer_keywords:
- project properties [C++], reusable
ms.openlocfilehash: bcf54be0531c7150c1506eb6f5dda2b5bc95161f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328697"
---
# <a name="share-or-reuse-visual-studio-project-settings"></a>Compartilhamento ou reutilização das configurações de projeto do Visual Studio

Para criar um grupo personalizado de configurações que você pode compartilhar com outros ou reutilizar em vários projetos, use **o Property Manager** para criar uma folha de *propriedade* (.props file) para armazenar as configurações de cada tipo de projeto que você deseja ser capaz de reutilizar ou compartilhar com outros. O uso de folhas de propriedade é muito menos propenso a erros do que outras maneiras de criar configurações "globais".

> [!IMPORTANT]
> **Arquivos .user e por que eles são problemáticos**
>
> As versões anteriores do Visual Studio usavam folhas de propriedades globais que tinham uma extensão de nome de arquivo .user e estavam localizadas na pasta \<perfil do usuário>\AppData\Local\Microsoft\MSBuild\v4.0\. Não recomendamos mais esses arquivos, pois definem propriedades para configurações do projeto com base no computador e no usuário. Essas configurações “globais” podem interferir com as compilações, especialmente quando você está definindo mais de uma plataforma no computador de compilação. Por exemplo, se você tiver um projeto do MFC e um projeto do Windows Phone, as propriedades .user serão inválidas para um deles. Folhas de propriedade reutilizáveis são mais flexíveis e mais robustas.
>
> Embora os arquivos .user ainda sejam instalados pelo Visual Studio e participem da herança de propriedade, eles são vazios por padrão. A melhor prática é excluir a referência a eles no **Gerenciador de Propriedades** para garantir que os projetos operem independentemente de qualquer configuração por usuário e por computador. É importante garantir o comportamento correto em um ambiente de SCC (controle do código-fonte).

Para exibir **o Gerenciador de**propriedades, na barra de menus, escolha **Exibir** > **o Gerenciador de propriedades** ou **exibir** > outro**gerenciador de propriedades do****Windows,** > dependendo das configurações.

Se você tiver um conjunto de propriedades comuns usadas com frequência que deseje aplicar a vários projetos, use o **Gerenciador de Propriedades** para capturá-las em um arquivo de *folha de propriedades* reutilizável que, por convenção, tem uma extensão de nome de arquivo .props. Você pode aplicar a folha (ou folhas) a novos projetos para que não precisar definir suas propriedades a partir do zero.

![Menu de atalho do Gerenciador de Propriedades](media/sharingnew.png "CompartilhandoNovo")

Em cada nó de configuração, você verá os nós de cada folha de propriedades que se aplica a essa configuração. O sistema adiciona folhas de propriedades que definem valores com base nas opções escolhidas no assistente de aplicativo no momento da criação do projeto. Clique com o botão direito do mouse em qualquer nó e escolha Propriedades para ver as propriedades que se aplicam a esse nó. Todas as folhas de propriedades são importadas automaticamente para a folha de propriedades "mestre" do projeto (ms.cpp.props) e são avaliadas na ordem em que são exibidas no Gerenciador de Propriedades. Mova-as para alterar a ordem de avaliação. As folhas de propriedades que são avaliadas posteriormente substituirão os valores nas planilhas avaliadas anteriormente. Consulte [Project property herherance](project-property-inheritance.md) para obter mais informações sobre a ordem de avaliação no arquivo .vcxproj, nos arquivos .props e .targets, variáveis de ambiente e na linha de comando.

Se você escolher **Adicionar Nova Folha de Propriedades do Projeto** e, em seguida, selecionar, por exemplo, a folha de propriedades MyProps.props, uma caixa de diálogo da página de propriedades será aberta. Observe que isso se aplica à folha de propriedades MyProps; as alterações feitas são gravadas na folha, não no arquivo de projeto (.vcxproj).

As propriedades em uma folha de propriedades são substituídas se a mesma propriedade for definida diretamente no arquivo .vcxproj.

Você pode importar uma folha de propriedades quantas vezes for necessário. Vários projetos em uma solução podem herdar configurações da mesma folha de propriedades, e um projeto pode ter várias folhas. Uma folha de propriedades em si pode herdar configurações de outra folha de propriedades.

Você também pode criar uma folha de propriedades para várias configurações. Para fazer isso, crie uma folha de propriedades para cada configuração, abra o menu de atalho de uma delas, escolha **Adicionar Folha de Propriedades Existente** e, em seguida, adicione as outras folhas. No entanto, se você usar uma folha de propriedade comum, esteja ciente de que quando você definir um imóvel, ele será definido para todas as configurações a que a folha se aplica, e que o IDE não mostra quais projetos ou outras folhas de propriedade estão herdando de uma determinada folha de propriedade.

Em grandes soluções que terão vários projetos, pode ser útil criar uma folha de propriedades no nível da solução. Quando você adicionar um projeto à solução, use o **Gerenciador de Propriedades** para adicionar a folha de propriedades ao projeto. Se for necessário no nível do projeto, você pode adicionar uma nova folha de propriedades para definir valores específicos do projeto.

> [!IMPORTANT]
> Um arquivo .props por padrão não participa do controle de origem porque não é criado como um item do projeto. Você pode adicionar manualmente o arquivo como um item de solução se quiser incluí-lo no controle de código-fonte.

#### <a name="to-create-a-property-sheet"></a>Para criar uma folha de propriedades

1. Na barra de menus, escolha **Exibir** > **gerenciador de propriedades** ou **exibir** > outro**gerenciador de propriedades do****Windows** > . O **Gerenciador de Propriedades** será aberto.

2. Para definir o escopo da folha de propriedades, selecione o item ao qual se aplica. Isso pode ser uma configuração específica ou outra folha de propriedades. Abra o menu de atalho desse item e, em seguida, escolha **Adicionar Nova Folha de Propriedades do Projeto**. Especifique um nome e um local.

3. No **Gerenciador de Propriedades**, abra a nova folha de propriedades e, em seguida, defina as propriedades que deseja incluir.
