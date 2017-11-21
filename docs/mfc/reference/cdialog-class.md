---
title: Classe CDialog | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDialog
- AFXWIN/CDialog
- AFXWIN/CDialog::CDialog
- AFXWIN/CDialog::Create
- AFXWIN/CDialog::CreateIndirect
- AFXWIN/CDialog::DoModal
- AFXWIN/CDialog::EndDialog
- AFXWIN/CDialog::GetDefID
- AFXWIN/CDialog::GotoDlgCtrl
- AFXWIN/CDialog::InitModalIndirect
- AFXWIN/CDialog::MapDialogRect
- AFXWIN/CDialog::NextDlgCtrl
- AFXWIN/CDialog::OnInitDialog
- AFXWIN/CDialog::OnSetFont
- AFXWIN/CDialog::PrevDlgCtrl
- AFXWIN/CDialog::SetDefID
- AFXWIN/CDialog::SetHelpID
- AFXWIN/CDialog::OnCancel
- AFXWIN/CDialog::OnOK
dev_langs: C++
helpviewer_keywords:
- CDialog [MFC], CDialog
- CDialog [MFC], Create
- CDialog [MFC], CreateIndirect
- CDialog [MFC], DoModal
- CDialog [MFC], EndDialog
- CDialog [MFC], GetDefID
- CDialog [MFC], GotoDlgCtrl
- CDialog [MFC], InitModalIndirect
- CDialog [MFC], MapDialogRect
- CDialog [MFC], NextDlgCtrl
- CDialog [MFC], OnInitDialog
- CDialog [MFC], OnSetFont
- CDialog [MFC], PrevDlgCtrl
- CDialog [MFC], SetDefID
- CDialog [MFC], SetHelpID
- CDialog [MFC], OnCancel
- CDialog [MFC], OnOK
ms.assetid: ca64b77e-2cd2-47e3-8eff-c2645ad578f9
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: b823d40d4504be0180c3af3a6fb5359bf86725cd
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cdialog-class"></a>Classe CDialog
A classe base usada para exibir caixas de diálogo na tela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDialog : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDialog::CDialog](#cdialog)|Constrói um objeto `CDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDialog::Create](#create)|Inicializa o objeto `CDialog`. Cria uma caixa de diálogo sem janela restrita e anexa-o para o `CDialog` objeto.|  
|[CDialog::CreateIndirect](#createindirect)|Cria uma caixa de diálogo sem janela restrita de um modelo de caixa de diálogo na memória (não-com base em recursos).|  
|[CDialog::DoModal](#domodal)|Chama uma caixa de diálogo modal e retorna quando terminar.|  
|[CDialog::EndDialog](#enddialog)|Fecha a caixa de diálogo modal.|  
|[CDialog::GetDefID](#getdefid)|Obtém a ID do controle de botão de pressão padrão para uma caixa de diálogo.|  
|[CDialog::GotoDlgCtrl](#gotodlgctrl)|Move o foco para um controle de caixa de diálogo especificada na caixa de diálogo.|  
|[CDialog::InitModalIndirect](#initmodalindirect)|Cria uma caixa de diálogo modal de um modelo de caixa de diálogo na memória (não-com base em recursos). Os parâmetros são armazenados até que a função `DoModal` é chamado.|  
|[CDialog::MapDialogRect](#mapdialogrect)|Converte as unidades de caixa de diálogo de um retângulo em unidades de tela.|  
|[CDialog::NextDlgCtrl](#nextdlgctrl)|Move o foco para o próximo controle de caixa de diálogo, na caixa de diálogo.|  
|[CDialog::OnInitDialog](#oninitdialog)|Ignorar para aumentar a inicialização da caixa de diálogo.|  
|[CDialog::OnSetFont](#onsetfont)|Substituição para especificar a fonte que é um controle de caixa de diálogo para usar quando ele desenha texto.|  
|[CDialog::PrevDlgCtrl](#prevdlgctrl)|Move o foco para o controle de caixa de diálogo anterior na caixa de diálogo.|  
|[CDialog::SetDefID](#setdefid)|O controle de botão de pressão de padrão de uma caixa de diálogo é alterado para um botão de ação especificado.|  
|[CDialog::SetHelpID](#sethelpid)|Define uma ID de ajuda contextual para a caixa de diálogo.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDialog::OnCancel](#oncancel)|Substituição para executar o botão Cancelar ou ação chave ESC. O padrão fecha a caixa de diálogo e **DoModal** retorna **IDCANCEL**.|  
|[CDialog::OnOK](#onok)|Substituição para executar a ação do botão Okey na caixa de diálogo modal. O padrão fecha a caixa de diálogo e `DoModal` retorna **IDOK**.|  
  
## <a name="remarks"></a>Comentários  
 Caixas de diálogo são de dois tipos: modal e sem janela restrita. Caixa de diálogo modal deve ser fechada pelo usuário antes do aplicativo continua. Uma caixa de diálogo sem janela restrita permite que o usuário exibir a caixa de diálogo e retornar à outra tarefa sem cancelar ou remover a caixa de diálogo.  
  
 Um `CDialog` objeto é uma combinação de um modelo de caixa de diálogo e um `CDialog`-classe derivada. Use o editor de caixa de diálogo para criar o modelo de caixa de diálogo e armazená-lo em um recurso, use o Assistente para Adicionar classe para criar uma classe derivada de `CDialog`.  
  
 Uma caixa de diálogo, como qualquer outra janela, recebe mensagens do Windows. Em uma caixa de diálogo que lhe interessam particularmente manipulação de mensagens de notificação de controles da caixa de diálogo já que é como o usuário interage com a caixa de diálogo. Use a janela Propriedades para selecionar quais mensagens que você deseja a alça e irá adicionar as entradas de mapa de mensagem apropriado e funções de membro de manipulador de mensagens para a classe para você. Você só precisa escrever código específico do aplicativo nas funções de membro do manipulador.  
  
 Se preferir, você pode sempre gravar entradas de mapa de mensagem e funções de membro manualmente.  
  
 Em todas, exceto a caixa de diálogo mais simples, você pode adicionar variáveis de membro para sua classe derivada da caixa de diálogo para armazenar dados inseridos nos controles da caixa de diálogo pelo usuário ou para exibir dados para o usuário. Você pode usar o assistente Adicionar variável para criar variáveis de membro e associá-los com controles. Ao mesmo tempo, você pode escolher um tipo de variável e o intervalo permitido de valores para cada variável. O Assistente de código adiciona as variáveis de membro para sua classe derivada da caixa de diálogo.  
  
 Um mapa de dados é gerado para manipular automaticamente a troca de dados entre as variáveis de membro e controles da caixa de diálogo. O mapa de dados fornece funções que inicializar os controles na caixa de diálogo com os valores apropriados, recuperam os dados e validar os dados.  
  
 Para criar uma caixa de diálogo modal, construir um objeto na pilha usando o construtor para a classe derivada da caixa de diálogo e, em seguida, chame `DoModal` para criar a janela de diálogo e controles. Se você quiser criar uma caixa de diálogo sem janela restrita, chame **criar** no construtor da classe do diálogo.  
  
 Você também pode criar um modelo na memória usando um [DLGTEMPLATE](http://msdn.microsoft.com/library/windows/desktop/ms645394) estrutura de dados, conforme descrito no SDK do Windows. Depois de construir um `CDialog` de objeto, chame [CreateIndirect](#createindirect) para criar uma sem janela restrita caixa de diálogo ou chamada [InitModalIndirect](#initmodalindirect) e [DoModal](#domodal) para criar um modal caixa de diálogo.  
  
 O mapa de dados do exchange e a validação é gravado em uma substituição de `CWnd::DoDataExchange` que é adicionado à sua nova classe de caixa de diálogo. Consulte o [DoDataExchange](../../mfc/reference/cwnd-class.md#dodataexchange) função de membro em `CWnd` para obter mais informações sobre a funcionalidade do exchange e a validação.  
  
 O programador e a chamada de framework `DoDataExchange` indiretamente por meio de uma chamada para [CWnd::UpdateData](../../mfc/reference/cwnd-class.md#updatedata).  
  
 A estrutura chama `UpdateData` quando o usuário clica no botão Okey para fechar a caixa de diálogo modal. (Os dados não serão recuperados se o botão Cancelar é clicado.) A implementação padrão de [OnInitDialog](#oninitdialog) também chama `UpdateData` para definir os valores iniciais dos controles. Você normalmente substitui `OnInitDialog` inicializar mais controles. `OnInitDialog`é chamado depois que todos os controles de caixa de diálogo são criados e antes da caixa de diálogo caixa será exibida.  
  
 Você pode chamar `CWnd::UpdateData` a qualquer momento durante a execução de uma caixa de diálogo modal ou sem janela restrita.  
  
 Se você desenvolver uma caixa de diálogo manualmente, você adiciona as variáveis de membro necessário na classe derivada da caixa de diálogo por conta própria, e adicionar funções de membro para definir ou obter esses valores.  
  
 Caixa de diálogo modal será fechada automaticamente quando o usuário pressiona os botões Okey ou cancelar ou quando seu código chama o `EndDialog` função de membro.  
  
 Quando você implementa uma caixa de diálogo sem janela restrita, sempre substituir o `OnCancel` função de membro e chame `DestroyWindow` de dentro dele. Não chame a classe base `CDialog::OnCancel`, pois ele chama `EndDialog`, que fará a caixa de diálogo invisíveis, mas não destruirá. Você também deve substituir `PostNcDestroy` para caixas de diálogo sem janela restrita para excluir **isso**, como caixas de diálogo sem janela restrita geralmente são alocadas com **novo**. Caixas de diálogo modais geralmente são criadas no quadro e não é necessário `PostNcDestroy` limpeza.  
  
 Para obter mais informações sobre `CDialog`, consulte:  
  
- [Caixas de diálogo](../../mfc/dialog-boxes.md)  
  
-   Artigo da Base de dados de Conhecimento Q262954: como: criar uma caixa de diálogo redimensionáveis com barras de rolagem  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="cdialog"></a>CDialog::CDialog  
 Para construir uma caixa de diálogo modal com base em recursos, chame qualquer formulário público do construtor.  
  
```  
explicit CDialog(
    LPCTSTR lpszTemplateName,  
    CWnd* pParentWnd = NULL);

 
explicit CDialog(
    UINT nIDTemplate,  
    CWnd* pParentWnd = NULL);  
  
CDialog();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszTemplateName`  
 Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.  
  
 `nIDTemplate`  
 Contém o número de identificação de um recurso de modelo de caixa de diálogo.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai ou o proprietário (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, janela de pai do objeto de caixa de diálogo é definida como a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Um formulário do construtor fornece acesso ao recurso da caixa de diálogo pelo nome do modelo. O outro construtor fornece acesso por número de identificação de modelo, geralmente com um **IDD _** prefixo (por exemplo, IDD_DIALOG1).  
  
 Para construir uma caixa de diálogo modal a partir de um modelo na memória, primeiro chamar o construtor sem parâmetros, protegido e, em seguida, chame `InitModalIndirect`.  
  
 Depois que você criar uma caixa de diálogo modal com um dos métodos acima, chame `DoModal`.  
  
 Para construir uma caixa de diálogo sem janela restrita, use o formato protegido do `CDialog` construtor. O construtor está protegido porque você deve derivar sua própria classe de caixa de diálogo para implementar uma caixa de diálogo sem janela restrita. Construção de uma caixa de diálogo sem janela restrita é um processo de duas etapas. Primeiro, chame o construtor; em seguida, chame o **criar** a função de membro para criar uma caixa de diálogo com base em recursos ou chamar `CreateIndirect` para criar a caixa de diálogo de um modelo na memória.  
  
##  <a name="create"></a>CDialog::Create  
 Chamar **criar** para criar uma caixa de diálogo sem janela restrita usando um modelo de caixa de diálogo de um recurso.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszTemplateName,  
    CWnd* pParentWnd = NULL);

 
virtual BOOL Create(
    UINT nIDTemplate,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszTemplateName`  
 Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, janela de pai do objeto de caixa de diálogo é definida como a janela principal do aplicativo.  
  
 `nIDTemplate`  
 Contém o número de identificação de um recurso de modelo de caixa de diálogo.  
  
### <a name="return-value"></a>Valor de retorno  
 As duas formas de retorno diferente de zero se a inicialização e a criação da caixa de diálogo foi bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode colocar a chamada para **criar** dentro do construtor ou call após o construtor é invocada.  
  
 Duas formas da **criar** função de membro são fornecidas para acessar o recurso de modelo de caixa de diálogo pelo nome do modelo ou o número de ID de modelo (por exemplo, IDD_DIALOG1).  
  
 Para o formulário, transmitir um ponteiro para o objeto de janela pai. Se `pParentWnd` é **nulo**, a caixa de diálogo será criada com sua janela pai ou proprietário definida para a janela principal do aplicativo.  
  
 O **criar** função membro retorna imediatamente após ele ter criado a caixa de diálogo.  
  
 Use o **WS_VISIBLE** no modelo de caixa de diálogo de estilo se a caixa de diálogo deve aparecer quando a janela pai é criada. Caso contrário, você deve chamar `ShowWindow`. Para obter os estilos de caixa de diálogo e seu aplicativo, consulte o [DLGTEMPLATE](http://msdn.microsoft.com/library/windows/desktop/ms645394) estrutura no SDK do Windows e [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) no *referência MFC*.  
  
 Use o `CWnd::DestroyWindow` função destruir uma caixa de diálogo criada pelo **criar** função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#62](../../mfc/codesnippet/cpp/cdialog-class_1.cpp)]  
  
##  <a name="createindirect"></a>CDialog::CreateIndirect  
 Chame essa função de membro para criar uma caixa de diálogo sem janela restrita a partir de um modelo de caixa de diálogo na memória.  
  
```  
virtual BOOL CreateIndirect(
    LPCDLGTEMPLATE lpDialogTemplate,  
    CWnd* pParentWnd = NULL,  
    void* lpDialogInit = NULL);

 
virtual BOOL CreateIndirect(
    HGLOBAL hDialogTemplate,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDialogTemplate`  
 Pontos de memória que contém um modelo de caixa de diálogo usado para criar a caixa de diálogo. Este modelo é na forma de um [DLGTEMPLATE](http://msdn.microsoft.com/library/windows/desktop/ms645394) informações de estrutura e o controle, conforme descrito no SDK do Windows.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai do objeto de caixa de diálogo (do tipo [CWnd](../../mfc/reference/cwnd-class.md)). Se for **nulo**, janela de pai do objeto de caixa de diálogo é definida como a janela principal do aplicativo.  
  
 `lpDialogInit`  
 Aponta para um **DLGINIT** recursos.  
  
 `hDialogTemplate`  
 Contém um identificador para a memória global que contém um modelo de caixa de diálogo. Este modelo é na forma de um **DLGTEMPLATE** estrutura e os dados para cada controle na caixa de diálogo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a caixa de diálogo foi criada e inicializada com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `CreateIndirect` função membro retorna imediatamente após ele ter criado a caixa de diálogo.  
  
 Use o **WS_VISIBLE** no modelo de caixa de diálogo de estilo se a caixa de diálogo deve aparecer quando a janela pai é criada. Caso contrário, você deve chamar `ShowWindow` para fazer com que ele seja exibido. Para obter mais informações sobre como você pode especificar outros estilos de caixa de diálogo no modelo, consulte o [DLGTEMPLATE](http://msdn.microsoft.com/library/windows/desktop/ms645394) estrutura no SDK do Windows.  
  
 Use o `CWnd::DestroyWindow` função destruir uma caixa de diálogo criada pelo `CreateIndirect` função.  
  
 Caixas de diálogo que contêm os controles ActiveX requerem informações adicionais fornecidas em um **DLGINIT** recursos. Para obter mais informações, consulte o artigo da Base de dados de Conhecimento Q231591, "como: usar um modelo de caixa de diálogo para criar uma caixa de diálogo do MFC com um controle ActiveX." Artigos da Base de dados de Conhecimento estão disponíveis em [http://support.microsoft.com](http://support.microsoft.com/).  
  
##  <a name="domodal"></a>CDialog::DoModal  
 Chame essa função de membro para invocar a caixa de diálogo modal e retornar o resultado da caixa de diálogo quando terminar.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `int` valor que especifica o valor da `nResult` parâmetro passado para o [CDialog::EndDialog](#enddialog) a função de membro, que é usada para fechar a caixa de diálogo. O valor de retorno é -1 se a função não foi possível criar a caixa de diálogo ou **IDABORT** se algum outro erro tiver ocorrido, caso em que a janela de saída conterá informações de erro [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro manipula toda a interação com o usuário enquanto a caixa de diálogo está ativa. Isso faz com que a caixa de diálogo modal; ou seja, o usuário não pode interagir com outras janelas até que a caixa de diálogo é fechada.  
  
 Se o usuário clica em um dos pushbuttons na caixa de diálogo, como Okey ou em Cancelar, uma função de membro de manipulador de mensagens, como [OnOK](#onok) ou [OnCancel](#oncancel), é chamado para tentar fechar a caixa de diálogo. O padrão `OnOK` função membro validar e atualizar os dados da caixa de diálogo e feche a caixa de diálogo com o resultado **IDOK**e o padrão `OnCancel` função membro fechará a caixa de diálogo com o resultado  **IDCANCEL** sem validar ou atualizar os dados da caixa de diálogo. Você pode substituir essas funções de manipulador de mensagens para alterar seu comportamento.  
  
> [!NOTE]
> `PreTranslateMessage`Agora é chamado para processamento de mensagem de caixa de diálogo modal.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#63](../../mfc/codesnippet/cpp/cdialog-class_2.cpp)]  
  
##  <a name="enddialog"></a>CDialog::EndDialog  
 Chame essa função de membro para encerrar uma caixa de diálogo modal.  
  
```  
void EndDialog(int nResult);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nResult`  
 Contém o valor a ser retornado da caixa de diálogo para o chamador de `DoModal`.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro retorna `nResult` como o valor de retorno `DoModal`. Você deve usar o `EndDialog` função concluir o processamento sempre que uma caixa de diálogo modal é criada.  
  
 Você pode chamar `EndDialog` a qualquer momento, mesmo em [OnInitDialog](#oninitdialog), no caso, você deve fechar a caixa de diálogo antes que ele é mostrada ou antes que o foco de entrada é definido.  
  
 `EndDialog`Não feche a caixa de diálogo imediatamente. Em vez disso, ele define um sinalizador que direciona a caixa de diálogo fechar assim que retorna o manipulador de mensagens atual.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#64](../../mfc/codesnippet/cpp/cdialog-class_3.cpp)]  
  
 [!code-cpp[NVC_MFCControlLadenDialog#65](../../mfc/codesnippet/cpp/cdialog-class_4.cpp)]  
  
##  <a name="getdefid"></a>CDialog::GetDefID  
 Chamar o `GetDefID` a função de membro para obter a ID do controle de botão de pressão padrão para uma caixa de diálogo.  
  
```  
DWORD GetDefID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de 32 bits ( `DWORD`). Se o botão de ação padrão tem um valor de ID, a palavra de ordem superior contém **DC_HASDEFID** e a palavra de ordem inferior contém o valor de ID. Se o botão de ação padrão não tem um valor de ID, o valor de retorno será 0.  
  
### <a name="remarks"></a>Comentários  
 Isso geralmente é um botão Okey.  
  
##  <a name="gotodlgctrl"></a>CDialog::GotoDlgCtrl  
 Move o foco para o controle especificado na caixa de diálogo.  
  
```  
void GotoDlgCtrl(CWnd* pWndCtrl);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWndCtrl`  
 Identifica a janela (controle) que deve receber o foco.  
  
### <a name="remarks"></a>Comentários  
 Para obter um ponteiro para o controle (janela filho) para passar como `pWndCtrl`, chame o `CWnd::GetDlgItem` função de membro, que retorna um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CWnd::GetDlgItem](../../mfc/reference/cwnd-class.md#getdlgitem).  
  
##  <a name="initmodalindirect"></a>CDialog::InitModalIndirect  
 Chame essa função de membro para inicializar um objeto de caixa de diálogo modal usando um modelo de caixa de diálogo que você construir na memória.  
  
```  
BOOL InitModalIndirect(
    LPCDLGTEMPLATE lpDialogTemplate,  
    CWnd* pParentWnd = NULL,  
    void* lpDialogInit = NULL);

 
    BOOL InitModalIndirect(
    HGLOBAL hDialogTemplate,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDialogTemplate`  
 Pontos de memória que contém um modelo de caixa de diálogo usado para criar a caixa de diálogo. Este modelo é na forma de um [DLGTEMPLATE](http://msdn.microsoft.com/library/windows/desktop/ms645394) informações de estrutura e o controle, conforme descrito no SDK do Windows.  
  
 `hDialogTemplate`  
 Contém um identificador para a memória global que contém um modelo de caixa de diálogo. Este modelo é na forma de um **DLGTEMPLATE** estrutura e os dados para cada controle na caixa de diálogo.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai ou o proprietário (do tipo [CWnd](../../mfc/reference/cwnd-class.md)) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, janela de pai do objeto de caixa de diálogo é definida como a janela principal do aplicativo.  
  
 `lpDialogInit`  
 Aponta para um **DLGINIT** recursos.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto de caixa de diálogo foi criado e inicializado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para criar uma caixa de diálogo modal indiretamente, alocar um bloco global de memória e preenchê-lo com o modelo de caixa de diálogo. Em seguida, chamar vazio `CDialog` construtor para construir o objeto de caixa de diálogo. Em seguida, chame `InitModalIndirect` para armazenar o identificador para o modelo de caixa de diálogo na memória. A caixa de diálogo do Windows é criada e exibida mais tarde, quando o [DoModal](#domodal) é chamada de função de membro.  
  
 Caixas de diálogo que contêm os controles ActiveX requerem informações adicionais fornecidas em um **DLGINIT** recursos. Para obter mais informações, consulte o artigo da Base de dados de Conhecimento Q231591, "como: usar um modelo de caixa de diálogo para criar uma caixa de diálogo do MFC com um controle ActiveX." Artigos da Base de dados de Conhecimento estão disponíveis em [http://support.microsoft.com](http://support.microsoft.com/).  
  
##  <a name="mapdialogrect"></a>CDialog::MapDialogRect  
 Chamada para converter as unidades de caixa de diálogo de um retângulo em unidades de tela.  
  
```  
void MapDialogRect(LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou [CRect](../../atl-mfc-shared/reference/crect-class.md) coordenadas do objeto que contém a caixa de diálogo a ser convertido.  
  
### <a name="remarks"></a>Comentários  
 Unidades de caixa de diálogo são informadas como a unidade base atual de caixa de diálogo derivada a média largura e altura de caracteres da fonte usada para o texto da caixa de diálogo. Uma unidade horizontal é um quarto da unidade de largura da base da caixa de diálogo e uma unidade vertical é um oitavo da unidade base altura da caixa de diálogo.  
  
 O **GetDialogBaseUnits** função Windows retorna informações sobre o tamanho da fonte do sistema, mas você pode especificar uma fonte diferente para cada caixa de diálogo se você usar o **DS_SETFONT** de estilo no arquivo de definição de recurso. O `MapDialogRect` função do Windows usa a fonte apropriada para essa caixa de diálogo.  
  
 O `MapDialogRect` função membro substitui as unidades de caixa de diálogo no `lpRect` com tela de unidades (pixels) para que o retângulo pode ser usado para criar uma caixa de diálogo ou posicionar um controle dentro de uma caixa.  
  
##  <a name="nextdlgctrl"></a>CDialog::NextDlgCtrl  
 Move o foco para o próximo controle na caixa de diálogo.  
  
```  
void NextDlgCtrl() const;  
```  
  
### <a name="remarks"></a>Comentários  
 Se o foco estiver no último controle na caixa de diálogo, ele move para o primeiro controle.  
  
##  <a name="oncancel"></a>CDialog::OnCancel  
 O framework chama esse método quando o usuário clica **Cancelar** ou pressiona a tecla ESC em uma caixa de diálogo modal ou sem janela restrita.  
  
```  
virtual void OnCancel();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para executar ações (como restaurar os dados antigos) quando um usuário fecha a caixa de diálogo clicando em **Cancelar** ou pressionar a tecla ESC. O padrão fecha a caixa de diálogo modal chamando [EndDialog](#enddialog) e fazendo com que [DoModal](#domodal) para retornar IDCANCEL.  
  
 Se você implementar o **Cancelar** botão em uma caixa de diálogo sem janela restrita, você deve substituir o `OnCancel` método e chame [DestroyWindow](../../mfc/reference/cwnd-class.md#destroywindow) dentro dele. Não chame o método de classe base, pois ele chama `EndDialog`, que será tornar invisível a caixa de diálogo, mas não destruída.  
  
> [!NOTE]
>  Você não pode substituir esse método quando você usa um `CFileDialog` objeto em um programa que é compilado no Windows XP. Para obter mais informações sobre `CFileDialog`, consulte [classe CFileDialog](../../mfc/reference/cfiledialog-class.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#66](../../mfc/codesnippet/cpp/cdialog-class_5.cpp)]  
  
##  <a name="oninitdialog"></a>CDialog::OnInitDialog  
 Este método é chamado em resposta ao `WM_INITDIALOG` mensagem.  
  
```  
virtual BOOL OnInitDialog();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica se o aplicativo definiu o foco de entrada para um dos controles na caixa de diálogo. Se `OnInitDialog` retorna diferente de zero, o Windows define o foco de entrada para o local padrão, o primeiro controle na caixa de diálogo. O aplicativo pode retornar 0 somente se ele tiver definido explicitamente o foco de entrada para um dos controles na caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 O Windows envia o `WM_INITDIALOG` mensagem para a caixa de diálogo durante a [criar](#create), [CreateIndirect](#createindirect), ou [DoModal](#domodal) chamadas, o que ocorrerem imediatamente antes da caixa de diálogo é exibida.  
  
 Substitua este método se desejar executar um processamento especial quando a caixa de diálogo é inicializada. A versão substituída, chame a classe base `OnInitDialog` , mas ignore o valor de retorno. Normalmente, você irá retornar `TRUE` de seu método substituído.  
  
 Chamadas de Windows a `OnInitDialog` função usando o procedimento padrão global para caixa de diálogo comuns a todas as caixas de diálogo de biblioteca Microsoft Foundation Class. Ele não chama essa função por meio de seu mapa de mensagem e, portanto, não é necessário uma entrada de mapa de mensagem para este método.  
  
> [!NOTE]
>  Você não pode substituir esse método quando você usa um `CFileDialog` objeto em um programa que é compilado em [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)]. Para obter mais informações sobre alterações para `CFileDialog` em [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)] consulte [classe CFileDialog](../../mfc/reference/cfiledialog-class.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#67](../../mfc/codesnippet/cpp/cdialog-class_6.cpp)]  
  
##  <a name="onok"></a>CDialog::OnOK  
 Chamado quando o usuário clica o **Okey** botão (o botão com uma ID de IDOK).  
  
```  
virtual void OnOK();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para executar ações quando o **Okey** botão está ativado. Se a caixa de diálogo inclui o exchange e a validação de dados automática, a implementação padrão desse método valida os dados de caixa de diálogo e atualiza as variáveis apropriadas em seu aplicativo.  
  
 Se você implementar o **Okey** botão em uma caixa de diálogo sem janela restrita, você deve substituir o `OnOK` método e chame [DestroyWindow](../../mfc/reference/cwnd-class.md#destroywindow) dentro dele. Não chame o método de classe base, pois ele chama [EndDialog](#enddialog) que faz com que a caixa de diálogo invisível, mas não destruir.  
  
> [!NOTE]
>  Você não pode substituir esse método quando você usa um `CFileDialog` objeto em um programa que é compilado no Windows XP. Para obter mais informações sobre `CFileDialog`, consulte [classe CFileDialog](../../mfc/reference/cfiledialog-class.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#68](../../mfc/codesnippet/cpp/cdialog-class_7.cpp)]  
  
##  <a name="onsetfont"></a>CDialog::OnSetFont  
 Especifica a fonte de que um controle de caixa de diálogo usará ao criar o texto.  
  
```  
Virtual void OnSetFont(CFont* pFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pFont`  
 Especifica um ponteiro para a fonte que será usada como a fonte padrão para todos os controles nessa caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 A caixa de diálogo usará a fonte especificada como padrão para todos os seus controles.  
  
 O editor de caixa de diálogo normalmente define a fonte da caixa de diálogo como parte do recurso de modelo de caixa de diálogo.  
  
> [!NOTE]
>  Você não pode substituir esse método quando você usa um `CFileDialog` objeto em um programa que é compilado em [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)]. Para obter mais informações sobre alterações para `CFileDialog` em [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)] consulte [classe CFileDialog](../../mfc/reference/cfiledialog-class.md).  
  
##  <a name="prevdlgctrl"></a>CDialog::PrevDlgCtrl  
 Define o foco para o controle anterior na caixa de diálogo.  
  
```  
void PrevDlgCtrl() const;  
```  
  
### <a name="remarks"></a>Comentários  
 Se o foco estiver no primeiro controle na caixa de diálogo, ele move para o último controle na caixa.  
  
##  <a name="setdefid"></a>CDialog::SetDefID  
 Altera o controle de botão de pressão de padrão de uma caixa de diálogo.  
  
```  
void SetDefID(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Especifica a ID do controle de botão de pressão que se tornará o padrão.  
  
##  <a name="sethelpid"></a>CDialog::SetHelpID  
 Define uma ID de ajuda contextual para a caixa de diálogo.  
  
```  
void SetHelpID(UINT nIDR);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDR*  
 Especifica a ID de ajuda contextual.  
  
## <a name="see-also"></a>Consulte também  
 [DLGCBR32 de exemplo do MFC](../../visual-cpp-samples.md)   
 [Exemplo MFC DLGTEMPL](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

