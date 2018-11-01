---
title: Assistente de classe MFC
ms.date: 11/04/2016
f1_keywords:
- vc.wizards.classwizard
helpviewer_keywords:
- wizards (MFC)
- MFC Class Wizard
ms.assetid: 8b0dd867-5d07-4214-99be-2a1c1995e6d9
ms.openlocfilehash: d80dc10467b5180158fcb0f681bbc728ada60764
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50471767"
---
# <a name="mfc-class-wizard"></a>Assistente de classe MFC

Permite adicionar manipuladores de mensagens e de mensagens para as classes em seu projeto. Você também pode iniciar outros assistentes ou adicionar uma classe ao seu projeto.

Para abrir o **MFC Class Wizard**diante a **Project** menu, clique em **Class Wizard**. Para abrir o assistente com um atalho de teclado, digite CTRL + SHIFT + X.

## <a name="uielement-list"></a>Lista UIElement

- **Projeto**

   O nome de um projeto em sua solução.

   Você pode selecionar outros projetos em sua solução na caixa de listagem suspensa.

- **Nome da classe**

   O nome de uma classe em seu projeto.

   Quando você seleciona uma classe na **nome da classe** lista, dados da classe preenche os controles na **MFC Class Wizard**. Quando você altera o valor de um controle, os dados na classe selecionada são afetados.

- **Adicionar classe**

   Permite adicionar uma classe de uma das várias fontes.

   Dependendo da sua seleção, o **MFC adicionar Class Wizard**, **Adicionar classe de Typelib assistente**, **Adicionar classe do Assistente de controle ActiveX**, ou **ODBC do MFC Assistente de consumidor** é iniciado.

- **Classe base**

   A classe base da classe que é exibido na **nome da classe**.

- **Declaração de classe**

   A classe na qual o **nome da classe** classe é declarada.

   O **declaração de classe** caixa é exibida somente se o nome nele difere do nome na **implementação da classe**.

- **recurso**

   A ID do recurso no **nome da classe**, se houver. Caso contrário, o **recurso** caixa estará vazia.

- **Implementação da classe**

   O nome do arquivo que contém a implementação da classe de **nome da classe**.

   Você pode selecionar um arquivo de implementação diferentes clicando na seta. A tabela a seguir lista as opções disponíveis.

   |Opção|Descrição|
   |------------|-----------------|
   |**Open File**|Fecha o Assistente de classe e abre o arquivo de implementação de classe atual.|
   |**Abrir pasta recipiente**|Abre a pasta que contém o arquivo de implementação de classe atual.|
   |**Copiar caminho completo para a área de transferência**|Copia o caminho do arquivo de implementação atual para a área de transferência.|

- **Comandos**

   Permite que você adicionar, excluir, editar ou procurar um comando e seu manipulador de mensagens.

   Para adicionar um manipulador, clique em **Add Handler**, ou clique duas vezes em um item de **IDs de objeto** lista ou **mensagens** lista. O nome da função, ID e mensagem resultante são exibidos na **funções de membro** lista.

   Para excluir um manipulador, selecione um item na **funções de membro** lista e, em seguida, clique em **manipulador excluir**.

   Para modificar um manipulador, clique duas vezes o item correspondente na **funções de membro** lista. Ou, selecione um item na caixa de listagem e, em seguida, clique em **editar código**.

- **Mensagens**

   Permite que você adicionar, excluir, editar ou procurar uma mensagem e seu manipulador de mensagens.

   Para adicionar um manipulador, clique em **Add Handler**, ou clique duas vezes em um item de **mensagens** lista.

   Para adicionar uma mensagem personalizada, clique em **Adicionar mensagem personalizada** ou pressione a tecla Enter e, em seguida, especifique valores de **Adicionar mensagem personalizada** caixa de diálogo. Na caixa de diálogo, você também pode selecionar **mensagem registrado** para lidar com uma mensagem de janela que é garantido que seja exclusivo em todo o sistema operacional.

- **Funções virtuais**

   Permite que você adicionar, excluir, editar ou pesquisar por uma função virtual ou uma função virtual substituída.

- **Variáveis de membro**

   Permite que você adicionar, excluir, editar ou pesquise por uma variável de membro.

- **Métodos**

   Permite que você adicionar, excluir, ou pesquisar um método e também ir para a definição ou declaração de um método.

   Para adicionar um método, clique em **Add Method**e, em seguida, especifique valores na **Add Method** caixa de diálogo.

   Para excluir um método, selecione um item na **métodos** lista e, em seguida, clique em **método Delete**.

   Para exibir uma declaração, selecione um item na **métodos** lista e, em seguida, clique em **ir para declaração.**

   Para exibir uma definição, clique duas vezes em um item de **métodos** lista. Ou, selecione um item na **métodos** lista e, em seguida, clique no **ir para definição** botão.

## <a name="see-also"></a>Consulte também

[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)
