---
title: Navegar pelo código C++ no Visual Studio
description: Use várias ferramentas no Visual Studio para navegar pela base de código C++.
ms.date: 05/28/2019
ms.openlocfilehash: cc13326dee14e952c78e521344a6244249179cb8
ms.sourcegitcommit: 59b7c18703d1ffd66827db0e2eeece490d3d8789
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/22/2020
ms.locfileid: "90683488"
---
# <a name="navigate-c-code-in-visual-studio"></a>Navegar pelo código C++ no Visual Studio

O Visual Studio fornece um conjunto de ferramentas que você pode usar para navegar pela base de código de forma rápida e eficiente.

## <a name="open-an-included-file"></a>Abrir um arquivo incluído

Clique com o botão direito do mouse em uma diretiva `#include` e selecione **Ir para o Documento**. Ou selecione **F12** com o cursor sobre essa linha para abrir o arquivo.

![Opção C&#43;&#43; ir para o menu do documento](../ide/media/go-to-document.png "Ir para o documento")

## <a name="toggle-headercode-file"></a>Ativar/Desativar Arquivo de Cabeçalho/Código

Você pode alternar entre um arquivo de cabeçalho e seu arquivo de origem correspondente. Clique com o botão direito do mouse em qualquer lugar do seu arquivo e selecione **Ativar/Desativar Arquivo de Cabeçalho/Código**. Ou selecione **Ctrl+K**, **Ctrl+O**.

## <a name="go-to-definitiondeclaration"></a>Ir para definição/declaração

Navegue até a definição de um símbolo de código, clicando com o botão direito do mouse no editor e selecionando **Ir para definição** ou pressionando **F12**. Navegue até uma declaração da mesma forma, clicando com o botão direito do mouse para abrir o menu de contexto ou selecionando **Ctrl+F12**.

![C&#43;&#43; ir para definição](../ide/media/go-to-def.png "Ir para definição")

## <a name="go-to"></a>Ir para

**Ir para** refere-se a um conjunto de recursos de navegação, com cada um fornecendo um tipo específico de resultado com base nos filtros especificados.

Abra **Ir para** com **Ctrl+,**. Esta ação criará uma caixa de pesquisa sobre o documento que você está editando.

![C&#43;&#43; ir para](../ide/media/go-to-cpp.png "Ir para")

**Ir para** inclui estes filtros de pesquisa:

- **Ir para linha** (**Ctrl + G**): ir rapidamente para uma linha diferente em seu documento atual.
- **Ir para todos** (**Ctrl +,**) ou (**Ctrl + T**): os resultados da pesquisa incluem tudo o que vem a seguir.
- **Ir para o arquivo** (**Ctrl 1, F**): Pesquise por arquivos em sua solução.
- **Ir para o tipo** (**Ctrl 1, T**): os resultados da pesquisa incluem:
  - Classes, structs e enumerações.
  - Interfaces e representantes (somente código gerenciado).
- **Ir para membro** (**Ctrl 1, M**): os resultados da pesquisa incluem:
  - Variáveis globais e funções globais.
  - Variáveis de membro de classe e funções de membro.
  - Constantes.
  - Itens de enumeração.
  - Propriedades e eventos.
- **Ir para símbolo** (**Ctrl 1, S**): os resultados da pesquisa incluem:
  - Resultados de Ir para Tipos e Ir para Membros.
  - Todos os demais constructos da linguagem C++, o que inclui macros.

Quando você invoca **Ir para** pela primeira vez com **Ctrl+**, **Ir para Todos** é ativado (sem filtro nos resultados da pesquisa). Em seguida, você pode selecionar o filtro desejado, usando os botões ao lado da caixa de pesquisa. Invoque um filtro específico usando o atalho de teclado correspondente. Esta ação abre a caixa de pesquisa **Ir para** com esse filtro pré-selecionado. Todos os atalhos de teclado são configuráveis.

Para aplicar um filtro de texto, inicie a consulta de pesquisa com o caractere correspondente do filtro seguido por um espaço. (**Ir para a linha** pode, opcionalmente, omitir o espaço.) Esses filtros de texto estão disponíveis:

- Ir para Todos: (sem filtro de texto)
- Ir para Número de Linha: :
- Ir para Arquivo: f
- Ir para Tipo: t
- Ir para Membro: m
- Ir para Símbolo: #

O seguinte exemplo mostra os resultados de uma operação *Ir para Arquivos* usando o filtro “f”:

![Captura de tela do menu ir para arquivos.](../ide/media/vs2017-go-to-results.png "Ir para o menu")

Para ver a lista de filtros de texto, digite um ? seguido por um espaço. Também é possível acessar os comandos **Ir para** com o menu **Editar**. Essa é outra maneira de lembrar-se do principal **ir para** atalhos de teclado.

![Captura de tela do menu ir para.](../ide/media/go-to-menu-cpp.png "Ir para o menu")

## <a name="find-or-find-in-files"></a>Localizar ou Localizar nos Arquivos

Execute uma pesquisa de texto de qualquer item na solução com **Localizar** (**Ctrl+F**) ou **Localizar nos Arquivos** (**Ctrl+Shift+F**).

A opção **Localizar** pode ter o escopo definido para uma seleção, o documento atual, todos os documentos abertos, o projeto atual ou a solução inteira. Você pode usar expressões regulares e texto sem formatação. Ela também realça todas as correspondências automaticamente no IDE.

![C&#43;&#43; localizar](../ide/media/find-cpp.png "Localizar")

A opção **Localizar nos Arquivos** é uma versão mais eficiente de **Localizar** que exibe os resultados na janela **Localizar Resultados**. Você pode pesquisar dependências de código externas, filtrar por tipos de arquivos e muito mais.

![Captura de tela da janela Localizar e substituir mostrando a página localizar nos arquivos.](../ide/media/find-in-files-cpp.png "Localizar em Arquivos")

Organize os resultados de **Localizar nos Arquivos** em duas janelas. Acrescente os resultados de várias pesquisas juntos. Selecione um resultado para ir até essa localização no arquivo.

![Captura de tela mostrando um resultado da pesquisa localizar no arquivo.](../ide/media/vs2017-find-in-files-results.png "Localizar em Arquivos")

Para obter mais informações, confira [Localizar nos Arquivos](/visualstudio/ide/find-in-files) na documentação do Visual Studio.

## <a name="find-all-references"></a>Localizar Todas as Referências

Para localizar todos os usos de um símbolo na base de código, coloque o cursor no símbolo ou logo após ele, clique com o botão direito do mouse e, em seguida, selecione **Localizar Todas as Referências**. Você pode filtrar, classificar ou agrupar os resultados de várias maneiras diferentes. Os resultados são populados de maneira incremental. Eles são classificados como Leituras ou Gravações para ajudar você a ver o que existe na solução, em vez de cabeçalhos do sistema ou outras bibliotecas.

![C&#43;&#43; localizar todas as referências](../ide/media/find-all-references-results-cpp.png "Localizar todas as referências")

Agrupe os resultados pelas seguintes categorias:

- Projeto, então Definição
- Somente Definição
- Definição, então Projeto
- Definição, então Caminho
- Definição, Projeto e, então, Caminho

#### <a name="filter-results"></a>Resultados do filtro

Para filtrar os resultados, passe o mouse sobre uma coluna e selecione o ícone de filtragem exibido. Filtre os resultados da primeira coluna para ocultar itens como referências de cadeias de caracteres e comentários que talvez você não deseje ver.

![C&#43;&#43; localizar todos os filtros de referências](../ide/media/find-all-references-filters-cpp.png "Localizar todos os filtros de referências")

- **Resultados confirmados**: referências de código reais para o símbolo que está sendo pesquisado. Por exemplo, a pesquisa de uma função de membro chamada `Size` retorna todas as referências a `Size` que correspondem ao escopo da classe que define `Size`.

- **Resultados desconfirmados**: esse filtro está desativado por padrão porque ele mostra os símbolos cujo nome corresponde, mas não as referências reais ao símbolo que você está procurando. Por exemplo, se você tiver duas classes, com cada uma definindo uma função de membro chamada `Size`, e executar uma pesquisa por `Size` em uma referência de um objeto de `Class1`, todas as referências a `Size` de `Class2` serão exibidas como desconfirmadas.

- **Resultados não processados**: as operações **Localizar todas as referências** podem levar tempo para serem concluídas em bases de código maiores, portanto, a lista de resultados mostra os resultados "não processados" aqui. Os resultados não processados correspondem ao nome do símbolo que está sendo pesquisado, mas que ainda não foi confirmado como uma referência de código real. Ative esse filtro para obter resultados mais rápidos. Apenas lembre-se de que alguns resultados podem não ser referências reais.

#### <a name="sort-results"></a>Classificar resultados

Classifique os resultados por qualquer coluna, selecionando essa coluna. Alterne entre ordem ascendente ou decrescente selecionando a coluna novamente.

## <a name="navigation-bar"></a>Barra de navegação

Navegue até a definição de um tipo em um arquivo ou até membros de tipo, usando a **barra de navegação** acima da janela do editor.

![Barra de navegação do C&#43;&#43; ](../ide/media/navbar-cpp.png "Barra de navegação")

## <a name="see-also"></a>Veja também

- [Ler e entender o código C++](read-and-understand-code-cpp.md)</br>
- [Editar e refatorar o código C++](read-and-understand-code-cpp.md)</br>
- [Colaborar com o Live Share para C++](live-share-cpp.md)
