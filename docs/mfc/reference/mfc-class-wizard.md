---
title: Assistente de classe MFC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.wizards.classwizard
dev_langs:
- C++
helpviewer_keywords:
- wizards (MFC)
- MFC Class Wizard
ms.assetid: 8b0dd867-5d07-4214-99be-2a1c1995e6d9
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 42e46853541b9770a61fba4314fbbb37dea80d43
ms.lasthandoff: 02/25/2017

---
# <a name="mfc-class-wizard"></a>Assistente de classe MFC
Permite adicionar mensagens e manipuladores de mensagens para classes no seu projeto. Você também pode iniciar outros assistentes ou adicionar uma classe ao seu projeto.  
  
 Para abrir o **MFC Class Wizard**, no **projeto** menu, clique em **Class Wizard**. Para abrir o assistente com um atalho de teclado, digite CTRL + SHIFT + X.  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Projeto**  
 O nome de um projeto em sua solução.  
  
 Você pode selecionar outros projetos na solução na caixa de listagem suspensa.  
  
 **Nome da classe**  
 O nome de uma classe em seu projeto.  
  
 Quando você seleciona uma classe no **nome da classe** lista, dados da classe preenche os controles a **MFC Class Wizard**. Quando você altera o valor de um controle, os dados na classe selecionada são afetados.  
  
 **Adicionar classe**  
 Permite adicionar uma classe de uma das várias fontes.  
  
 Dependendo da sua seleção, o **Assistente de classe do MFC adicionar**, **Adicionar classe de Typelib assistente**, **classe do ActiveX Assistente para adicionar controle**, ou **Assistente de consumidor ODBC MFC** é iniciado.  
  
 **Classe base**  
 A classe base da classe que é exibida no **nome da classe**.  
  
 **Declaração de classe**  
 A classe na qual o **nome da classe** classe é declarada.  
  
 O **declaração de classe** caixa é exibida somente se o nome do difere do nome em **implementação da classe**.  
  
 **Recurso**  
 A ID do recurso no **nome da classe**, se houver. Caso contrário, o **recursos** caixa estiver vazia.  
  
 **Implementação da classe**  
 O nome do arquivo que contém a implementação da classe de **nome da classe**.  
  
 Você pode selecionar um arquivo de implementação diferentes clicando na seta. A tabela a seguir lista as opções disponíveis.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Abrir arquivo**|Sai do Assistente de classe e abre o arquivo de implementação de classe atual.|  
|**Abra que contém a pasta**|Abre a pasta que contém o arquivo de implementação de classe atual.|  
|**Copiar caminho completo para a área de transferência**|Copia o caminho do arquivo de implementação atual para a área de transferência.|  
  
 **Comandos**  
 Permite adicionar, excluir, editar ou pesquisar um comando e o manipulador de mensagens.  
  
 Para adicionar um manipulador, clique em **Adicionar manipulador**, ou clique duas vezes em um item de **IDs de objeto** lista ou **mensagens** lista. O nome da função, ID e mensagem resultante são exibidos na **funções de membro** lista.  
  
 Para excluir um manipulador, selecione um item no **funções de membro** lista e, em seguida, clique em **excluir manipulador**.  
  
 Para modificar um manipulador, clique duas vezes no item correspondente no **funções de membro** lista. Ou, selecione um item na caixa de listagem e, em seguida, clique em **editar código**.  
  
 **Mensagens**  
 Permite adicionar, excluir, editar ou pesquisar uma mensagem e seu manipulador de mensagens.  
  
 Para adicionar um manipulador, clique em **Adicionar manipulador**, ou clique duas vezes em um item de **mensagens** lista.  
  
 Para adicionar uma mensagem personalizada, clique em **Adicionar mensagem personalizada** ou pressione a tecla Enter e, em seguida, especifique valores de **Adicionar mensagem personalizada** caixa de diálogo. Na caixa de diálogo, você também pode selecionar **mensagem registrada** para lidar com uma mensagem da janela é garantida como sendo exclusivo em todo o sistema operacional.  
  
 **Funções virtuais**  
 Permite adicionar, excluir, editar ou pesquisar uma função virtual ou uma função virtual substituída.  
  
 **Variáveis de membro**  
 Permite adicionar, excluir, editar ou pesquisar uma variável de membro.  
  
 **Métodos**  
 Permite adicionar, excluir, ou procure um método e também ir para a definição ou declaração de um método.  
  
 Para adicionar um método, clique em **Adicionar método**e especifique valores no **Adicionar método** caixa de diálogo.  
  
 Para excluir um método, selecione um item no **métodos** lista e, em seguida, clique em **método Delete**.  
  
 Para exibir uma declaração, selecione um item no **métodos** lista e, em seguida, clique em **ir para declaração.**  
  
 Para exibir uma definição, clique duas vezes em um item de **métodos** lista. Ou, selecione um item no **métodos** lista e, em seguida, clique no **ir para definição** botão.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)

