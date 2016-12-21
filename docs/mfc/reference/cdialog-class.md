---
title: "Classe de CDialog | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDialog"
  - "Caixas de diálogo MFC, classe base"
  - "caixas de diálogo modais, criando"
  - "caixas de diálogo sem-modo, criando"
  - "caixas de diálogo sem-modo, exibir"
ms.assetid: ca64b77e-2cd2-47e3-8eff-c2645ad578f9
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe base usada para exibir caixas de diálogo na tela.  
  
## Sintaxe  
  
```  
class CDialog : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDialog::CDialog](../Topic/CDialog::CDialog.md)|Constrói um objeto de `CDialog` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDialog::Create](../Topic/CDialog::Create.md)|Inicializa o objeto de `CDialog` .  Cria uma caixa de diálogo sem\-modo e anexá\-la ao objeto de `CDialog` .|  
|[CDialog::CreateIndirect](../Topic/CDialog::CreateIndirect.md)|Cria uma caixa de diálogo sem\-modo de um modelo da caixa de diálogo na memória \(não com base nos recursos\).|  
|[CDialog::DoModal](../Topic/CDialog::DoModal.md)|Chama uma caixa de diálogo modal e retorna quando acaba.|  
|[CDialog::EndDialog](../Topic/CDialog::EndDialog.md)|Fechando uma caixa de diálogo modal.|  
|[CDialog::GetDefID](../Topic/CDialog::GetDefID.md)|Obtém a identificação do controle de teclas padrão para uma caixa de diálogo.|  
|[CDialog::GotoDlgCtrl](../Topic/CDialog::GotoDlgCtrl.md)|Move o foco em um controle específico da caixa de diálogo na caixa de diálogo.|  
|[CDialog::InitModalIndirect](../Topic/CDialog::InitModalIndirect.md)|Cria uma caixa de diálogo modal de um modelo da caixa de diálogo na memória \(não com base nos recursos\).  Os parâmetros são armazenadas até que a função está `DoModal` chamada.|  
|[CDialog::MapDialogRect](../Topic/CDialog::MapDialogRect.md)|Converte as unidades de diálogo de um retângulo para selecionar unidades.|  
|[CDialog::NextDlgCtrl](../Topic/CDialog::NextDlgCtrl.md)|Mova o foco para o próximo controle da caixa de diálogo na caixa de diálogo.|  
|[CDialog::OnInitDialog](../Topic/CDialog::OnInitDialog.md)|Substituição para aumentar a inicialização da caixa de diálogo.|  
|[CDialog::OnSetFont](../Topic/CDialog::OnSetFont.md)|Substituição para especificar a fonte que um controle caixa de diálogo é usar quando desenha texto.|  
|[CDialog::PrevDlgCtrl](../Topic/CDialog::PrevDlgCtrl.md)|Mova o foco para o controle anterior da caixa de diálogo na caixa de diálogo.|  
|[CDialog::SetDefID](../Topic/CDialog::SetDefID.md)|Altera o controle de teclas padrão para uma caixa de diálogo para uma tecla especificada.|  
|[CDialog::SetHelpID](../Topic/CDialog::SetHelpID.md)|Define um ID da ajuda contextual para a caixa de diálogo.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDialog::OnCancel](../Topic/CDialog::OnCancel.md)|Substitua para executar o botão cancelar a ação ou da tecla ESC.  A opção fechar a caixa de diálogo e retorna **IDCANCEL**de **DoModal** .|  
|[CDialog::OnOK](../Topic/CDialog::OnOK.md)|Substituição para executar a ação do botão OK em uma caixa de diálogo modal.  A opção fechar a caixa de diálogo e retorna **IDOK**de `DoModal` .|  
  
## Comentários  
 Caixas de diálogo são de dois tipos: modal e sem\-modo.  Uma caixa de diálogo modal deve ser fechada pelo usuário antes que o aplicativo continue.  Uma caixa de diálogo sem\-modo permite ao usuário exibir a caixa de diálogo e retorna a outra tarefa sem cancelar ou remova a caixa de diálogo.  
  
 Um objeto de `CDialog` é uma combinação de um modelo da caixa de diálogo e um `CDialog`\- classe derivada.  Use o editor de diálogo para criar o modelo da caixa de diálogo e armazená\-lo em um recurso, então use o assistente para adicionar classe para criar uma classe derivada de `CDialog`.  
  
 Uma caixa de diálogo, como qualquer outra janela, recebe mensagens do windows.  Em uma caixa de diálogo, particularmente você está interessado em notificações de manipulação dos controles da caixa de diálogo desde que é como o usuário interage com a caixa de diálogo.  Usar a janela de propriedades para selecionar as mensagens que você deseja manipular e adicionar as entradas de mapa mensagem\- e funções de membro apropriadas de mensagem\- manipulador a classe para você.  Você só precisa escrever código específico do aplicativo nas funções de membro do manipulador.  
  
 Se você preferir, você sempre pode escrever entradas e funções de membro de mapa mensagem\- manualmente.  
  
 Em casos mas na caixa de diálogo para mais trivial, você adiciona variáveis de membro a sua classe derivada da caixa de diálogo para armazenar dados inseridos para controles da caixa de diálogo pelo usuário ou para exibir dados para o usuário.  Você pode usar o assistente para adicionar variável criar variáveis de membro e para associá\-los com os controles.  A o mesmo tempo, você escolher um tipo de variável e um intervalo de valores permitido para cada variável.  O assistente de código a seguir adiciona as variáveis de membro a sua classe derivada da caixa de diálogo.  
  
 Um mapa de dados é gerado para tratar automaticamente a troca de dados entre as variáveis de membro e os controles da caixa de diálogo.  O mapa de dados fornece as funções que inicializam controles na caixa de diálogo com os valores apropriados, recuperar os dados, e validar os dados.  
  
 Para criar uma caixa de diálogo modal, construir um objeto na pilha usando o construtor para a classe derivado da caixa de diálogo e então chame `DoModal` para criar a janela da caixa de diálogo e seus controles.  Se você desejar criar uma caixa de diálogo sem\-modo, chame **Criar** no construtor de classe da caixa de diálogo.  
  
 Você também pode criar um modelo na memória usando uma estrutura de dados de [DLGTEMPLATE](http://msdn.microsoft.com/library/windows/desktop/ms645394) como descrito em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  Depois que você constrói um objeto de `CDialog` , chame [CreateIndirect](../Topic/CDialog::CreateIndirect.md) para criar uma caixa de diálogo sem\-modo, ou a chamada [InitModalIndirect](../Topic/CDialog::InitModalIndirect.md) e [DoModal](../Topic/CDialog::DoModal.md) para criar uma caixa de diálogo modal.  
  
 O mapa de dados de troca e de validação é escrito em uma substituição de `CWnd::DoDataExchange` que é adicionada à sua nova classe da caixa de diálogo.  Consulte a função de membro de [DoDataExchange](../Topic/CWnd::DoDataExchange.md) em `CWnd` para mais na funcionalidade de troca e validação.  
  
 O programador e a estrutura chamam `DoDataExchange` indiretamente com uma chamada a [CWnd::UpdateData](../Topic/CWnd::UpdateData.md).  
  
 A estrutura chama `UpdateData` quando o usuário clica no botão OK para fechar a caixa de diálogo modal.  \(Os dados não são recuperados se o botão cancelar for clicado.\) A implementação padrão de [OnInitDialog](../Topic/CDialog::OnInitDialog.md) também chama `UpdateData` para definir os valores iniciais dos controles.  Você normalmente substitui `OnInitDialog` para inicializar mais controles.  `OnInitDialog` é chamado os controles de caixa de diálogo é criado e quando imediatamente antes da caixa de diálogo é exibida.  
  
 Você pode chamar `CWnd::UpdateData` a qualquer momento durante a execução de uma caixa de diálogo modal ou sem janela restrita.  
  
 Se você desenvolver uma caixa de diálogo manualmente, você adiciona as variáveis de membros necessários para a classe derivado da caixa de diálogo você mesmo, e você adicionar funções de membro para obter ou definir esses valores.  
  
 Uma caixa de diálogo modal é fechado automaticamente quando o usuário pressionar os botões OK ou cancelar ou quando seu código chama a função de membro de `EndDialog` .  
  
 Quando você implementa uma caixa de diálogo sem\-modo, sempre substituir a função de membro de `OnCancel` e chamar `DestroyWindow` de dentro de ele.  Não chamar a classe base `CDialog::OnCancel`, porque chama `EndDialog`, que irão a caixa de diálogo invisível mas não o destruirá.  Você também deve substituir `PostNcDestroy` para caixas de diálogo sem\-modo para excluir **this**, desde que as caixas de diálogo sem\-modo são atribuídas geralmente com **new**.  Caixas de diálogo modais geralmente são construídas no quadro e não precisam a limpeza de `PostNcDestroy` .  
  
 Para obter mais informações sobre, consulte: `CDialog`  
  
-   [Caixas de diálogo](../../mfc/dialog-boxes.md)  
  
-   Artigo de Base de Dados de Conhecimento Q262954: HOWTO: crie uma caixa de diálogo de Resizeable com as barras de rolagem  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CDialog`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [O MFC exemplos DLGCBR32](../../top/visual-cpp-samples.md)   
 [Exemplo DLGTEMPL MFC](../../top/visual-cpp-samples.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)