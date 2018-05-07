---
title: Classe CWinFormsControl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CWinFormsControl
- AFXWINFORMS/CWinFormsControl
- AFXWINFORMS/CWinFormsControl::CWinFormsControl
- AFXWINFORMS/CWinFormsControl::CreateManagedControl
- AFXWINFORMS/CWinFormsControl::GetControl
- AFXWINFORMS/CWinFormsControl::GetControlHandle
dev_langs:
- C++
helpviewer_keywords:
- CWinFormsControl [MFC], CWinFormsControl
- CWinFormsControl [MFC], CreateManagedControl
- CWinFormsControl [MFC], GetControl
- CWinFormsControl [MFC], GetControlHandle
ms.assetid: 6406dd7b-fb89-4a18-ac3a-c010d6b6289a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0d126c7e6ef77142f20a9dd9d7ed68c44ede5fc1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cwinformscontrol-class"></a>Classe CWinFormsControl
Fornece a funcionalidade básica para a hospedagem de um controle de formulários do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class TManagedControl>  
class CWinFormsControl : public CWnd  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TManagedControl`  
 Um controle de formulários do Windows do .NET Framework a ser exibido no aplicativo do MFC.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinFormsControl::CWinFormsControl](#cwinformscontrol)|Constrói um objeto de wrapper de controle de formulários do Windows MFC.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinFormsControl::CreateManagedControl](#createmanagedcontrol)|Cria um controle de formulários do Windows em um contêiner do MFC.|  
|[CWinFormsControl::GetControl](#getcontrol)|Recupera um ponteiro para o controle de formulários do Windows.|  
|[CWinFormsControl::GetControlHandle](#getcontrolhandle)|Recupera um identificador para o controle de formulários do Windows.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinFormsControl::operator-&gt;](#operator_-_gt)|Substitui [CWinFormsControl::GetControl](#getcontrol) em expressões.|  
|[CWinFormsControl::operator TManagedControl ^](#operator_tmanagedcontrol)|Converte um tipo como um ponteiro para um controle de formulários do Windows.|  
  
## <a name="remarks"></a>Comentários  
 O `CWinFormsControl` classe fornece a funcionalidade básica para a hospedagem de um controle de formulários do Windows.  
  
 Para obter mais informações sobre como usar formulários do Windows, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
 Seu código MFC não armazenar em cache os identificadores de janela (geralmente armazenados em `m_hWnd`). Algumas propriedades de controle de formulários do Windows requerem que o Win32 subjacente `Window` ser destruído e recriado usando `DestroyWindow` e `CreateWindow`. Os identificadores de implementação de formulários do Windows MFC a `Destroy` e `Create` eventos dos controles para atualizar o `m_hWnd` membro.  
  
> [!NOTE]
>  Integração de formulários do Windows MFC funciona apenas em projetos que vincular dinamicamente a MFC (no qual AFXDLL é definido).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinforms.h  
  
##  <a name="createmanagedcontrol"></a>  CWinFormsControl::CreateManagedControl  
 Cria um controle de formulários do Windows em um contêiner do MFC.  
  
```  
inline BOOL CreateManagedControl(
    System::Type^ pType,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    int nID)  
inline BOOL CreateManagedControl(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    int nID);

 
inline BOOL CreateManagedControl(
    DWORD dwStyle,  
    int nPlaceHolderID,  
    CWnd* pParentWnd);

 
inline BOOL CreateManagedControl(
    typename TManagedControl^ pControl,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    int nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pType`  
 O tipo de dados do controle a ser criado. Deve ser um [tipo](https://msdn.microsoft.com/en-us/library/system.type) tipo de dados.  
  
 `dwStyle`  
 O estilo da janela para aplicar ao controle. Especificar uma combinação de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles). Atualmente, há suporte para apenas os seguintes estilos: WS_TABSTOP, WS_VISIBLE, WS_DISABLED e WS_GROUP.  
  
 `rect`  
 Um [estrutura RECT](../../mfc/reference/rect-structure1.md) que define as coordenadas dos cantos superior esquerdo e direito inferior do controle (primeiro sobrecarregar somente).  
  
 `nPlaceHolderID`  
 O identificador do controle de suporte local estática colocada no Editor de recursos. O controle de formulários do Windows recentemente criado substitui o controle estático, supondo que sua posição, ordem z e estilos (segunda sobrecarga somente).  
  
 `pParentWnd`  
 Um ponteiro para a janela pai.  
  
 `nID`  
 O número de identificação de recurso a ser atribuído ao controle recém-criado.  
  
 `pControl`  
 Uma instância de um controle de formulários do Windows a ser associado com a [CWinFormsControl](../../mfc/reference/cwinformscontrol-class.md) (somente sobrecarga quarta) do objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retorna um valor diferente de zero. Caso contrário, retorna zero.  
  
### <a name="remarks"></a>Comentários  
 Esse método cria um controle de formulários do Windows do .NET Framework em um contêiner do MFC.  
  
 A primeira sobrecarga do método aceita um tipo de dados do .NET Framework `pType` para que o MFC pode criar um novo objeto desse tipo. `pType` deve ser um [tipo](https://msdn.microsoft.com/en-us/library/system.type) tipo de dados.  
  
 A segunda sobrecarga do método cria um controle de formulários do Windows com base no `TManagedControl` parâmetro de modelo do `CWinFormsControl` classe. O tamanho e a posição do controle se baseia o `RECT` estrutura passado para o método. Somente `dwStyle` é importante para os estilos.  
  
 A terceira sobrecarga do método cria um controle de formulários do Windows que substitui um controle estático, destruí-lo e supondo que sua posição, ordem z e estilos. O controle estático serve apenas como um espaço reservado para o controle de formulários do Windows. Ao criar o controle, essa sobrecarga combina os estilos de `dwStyle` com estilos de recurso do controle estático.  
  
 A quarta sobrecarga do método permite que você passe em um controle de formulários do Windows já instanciado `pControl` que MFC será ajustado. Ele deve ser do mesmo tipo que o `TManagedControl` parâmetro de modelo do `CWinFormsControl` classe.  
  
 Consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md) para obter exemplos usando o formulário do Windows controla.  
  
##  <a name="cwinformscontrol"></a>  CWinFormsControl::CWinFormsControl  
 Constrói um objeto de wrapper de controle de formulários do Windows MFC.  
  
```  
CWinFormsControl();
```  
  
### <a name="remarks"></a>Comentários  
 O controle de formulários do Windows é instanciado quando você chamar [CWinFormsControl::CreateManagedControl](#createmanagedcontrol).  
  
##  <a name="getcontrol"></a>  CWinFormsControl::GetControl  
 Recupera um ponteiro para o controle de formulários do Windows.  
  
```  
inline TManagedControl^ GetControl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o controle de formulários do Windows.  
  
### <a name="example"></a>Exemplo  
  Consulte [CWinFormsControl::CreateManagedControl](#createmanagedcontrol).  
  
##  <a name="getcontrolhandle"></a>  CWinFormsControl::GetControlHandle  
 Recupera um identificador para o controle de formulários do Windows.  
  
```  
inline HWND GetControlHandle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um identificador para o controle de formulários do Windows.  
  
### <a name="remarks"></a>Comentários  
 `GetControlHandle` é um método auxiliar que retorna o identificador de janela armazenado nas propriedades do controle do .NET Framework. O valor do identificador de janela é copiado para [CWnd::m_hWnd](../../mfc/reference/cwnd-class.md#m_hwnd) durante a chamada para [CWnd::Attach](../../mfc/reference/cwnd-class.md#attach).  
  
##  <a name="operator_-_gt"></a>  CWinFormsControl::operator-&gt;  
 Substitui [CWinFormsControl::GetControl](#getcontrol) em expressões.  
  
```  
inline TManagedControl^  operator->() const;  
```  
  
### <a name="remarks"></a>Comentários  
 Este operador fornece uma sintaxe conveniente que substitui `GetControl` em expressões.  
  
 Para obter mais informações sobre os formulários do Windows, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
##  <a name="operator_tmanagedcontrol"></a>  CWinFormsControl::operator TManagedControl ^  
 Converte um tipo como um ponteiro para um controle de formulários do Windows.  
  
```  
inline operator TManagedControl^() const;  
```  
  
### <a name="remarks"></a>Comentários  
 Este operador passa `CWinFormsControl<TManagedControl>` para funções que aceitam um ponteiro para um controle de formulários do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWinFormsDialog](../../mfc/reference/cwinformsdialog-class.md)   
 [Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)
