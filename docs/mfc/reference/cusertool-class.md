---
title: Classe CUserTool
ms.date: 11/04/2016
f1_keywords:
- CUserTool
- AFXUSERTOOL/CUserTool
- AFXUSERTOOL/CUserTool::CopyIconToClipboard
- AFXUSERTOOL/CUserTool::DrawToolIcon
- AFXUSERTOOL/CUserTool::GetCommand
- AFXUSERTOOL/CUserTool::GetCommandId
- AFXUSERTOOL/CUserTool::Invoke
- AFXUSERTOOL/CUserTool::Serialize
- AFXUSERTOOL/CUserTool::SetCommand
- AFXUSERTOOL/CUserTool::SetToolIcon
- AFXUSERTOOL/CUserTool::LoadDefaultIcon
- AFXUSERTOOL/CUserTool::m_strArguments
- AFXUSERTOOL/CUserTool::m_strInitialDirectory
- AFXUSERTOOL/CUserTool::m_strLabel
helpviewer_keywords:
- CUserTool [MFC], CopyIconToClipboard
- CUserTool [MFC], DrawToolIcon
- CUserTool [MFC], GetCommand
- CUserTool [MFC], GetCommandId
- CUserTool [MFC], Invoke
- CUserTool [MFC], Serialize
- CUserTool [MFC], SetCommand
- CUserTool [MFC], SetToolIcon
- CUserTool [MFC], LoadDefaultIcon
- CUserTool [MFC], m_strArguments
- CUserTool [MFC], m_strInitialDirectory
- CUserTool [MFC], m_strLabel
ms.assetid: 7c287d3e-d012-488d-b4e1-aa0f83f294bb
ms.openlocfilehash: b73cb3d3c6e244a9aa41a91a3ee9ff1efa98d496
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502239"
---
# <a name="cusertool-class"></a>Classe CUserTool

Uma ferramenta de usuário é um item de menu que executa um aplicativo externo. A guia **ferramentas** da caixa de diálogo **Personalizar** ( [Classe CMFCToolBarsCustomizeDialog](../../mfc/reference/cmfctoolbarscustomizedialog-class.md)) permite que o usuário adicione ferramentas de usuário e especifique o nome, o comando, os argumentos e o diretório inicial para cada ferramenta de usuário.

## <a name="syntax"></a>Sintaxe

```
class CUserTool : public CObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CUserTool::CopyIconToClipboard](#copyicontoclipboard)||
|[CUserTool::DrawToolIcon](#drawtoolicon)|Desenha o ícone da ferramenta do usuário em um retângulo especificado.|
|[CUserTool::GetCommand](#getcommand)|Retorna uma cadeia de caracteres que contém o texto do comando associado à ferramenta do usuário.|
|[CUserTool::GetCommandId](#getcommandid)|Retorna a ID de comando do item de menu da ferramenta de usuário.|
|[CUserTool::Invoke](#invoke)|Executa o comando associado à ferramenta do usuário.|
|[CUserTool:: Serialize](#serialize)|Lê ou grava esse objeto de ou para um arquivo. (Substitui [CObject:: Serialize](../../mfc/reference/cobject-class.md#serialize).)|
|[CUserTool::SetCommand](#setcommand)|Define o comando associado à ferramenta do usuário.|
|[CUserTool::SetToolIcon](#settoolicon)|Carrega o ícone da ferramenta do usuário a partir do aplicativo associado à ferramenta.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CUserTool::LoadDefaultIcon](#loaddefaulticon)|Carrega o ícone padrão para uma ferramenta de usuário.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[CUserTool::m_strArguments](#m_strarguments)|Os argumentos de linha de comando para a ferramenta do usuário.|
|[CUserTool::m_strInitialDirectory](#m_strinitialdirectory)|O diretório inicial para a ferramenta de usuário.|
|[CUserTool::m_strLabel](#m_strlabel)|O nome da ferramenta exibida no item de menu para a ferramenta.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre como habilitar as ferramentas de usuário em seu aplicativo, consulte [classe CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar uma ferramenta a partir `CUserToolsManager` de um objeto, `m_strLabel` definir a variável de membro e definir o aplicativo que a ferramenta do usuário executa. Este trecho de código faz parte do [exemplo de demonstração do Visual Studio](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#35](../../mfc/codesnippet/cpp/cusertool-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CUserTool](../../mfc/reference/cusertool-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxusertool. h

##  <a name="copyicontoclipboard"></a>  CUserTool::CopyIconToClipboard

Para obter mais detalhes, consulte o código-fonte localizado na pasta **vc\\atlmfc\\src\\MFC** da instalação do Visual Studio.

```
BOOL CopyIconToClipboard();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="drawtoolicon"></a>CUserTool::D rawToolIcon

Desenha o ícone da ferramenta do usuário no centro de um retângulo especificado.

```
void DrawToolIcon(
    CDC* pDC,
    const CRect& rectImage);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Um ponteiro para um contexto de dispositivo.

*rectImage*<br/>
no Especifica as coordenadas da área para exibir o ícone.

##  <a name="getcommand"></a>CUserTool:: GetCommand

Retorna uma cadeia de caracteres que contém o texto do comando associado à ferramenta do usuário.

```
const CString& GetCommand() const;
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao `CString` objeto que contém o texto do comando associado à ferramenta do usuário.

##  <a name="getcommandid"></a>  CUserTool::GetCommandId

Retorna a ID de comando da ferramenta de usuário.

```
UINT GetCommandId() const;
```

### <a name="return-value"></a>Valor de retorno

A ID de comando desta ferramenta de usuário.

##  <a name="invoke"></a>  CUserTool::Invoke

Executa o comando associado à ferramenta do usuário.

```
virtual BOOL Invoke();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o comando foi executado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chama [ShellExecute](/windows/win32/api/shellapi/nf-shellapi-shellexecutew) para executar um comando associado à ferramenta User. A função falhará se o comando estiver vazio ou se [ShellExecute](/windows/win32/api/shellapi/nf-shellapi-shellexecutew) falhar.

##  <a name="loaddefaulticon"></a>  CUserTool::LoadDefaultIcon

Carrega o ícone padrão para uma ferramenta de usuário.

```
virtual HICON LoadDefaultIcon();
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o ícone carregado (HICON) ou nulo se o ícone padrão não puder ser carregado.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando não é possível carregar um ícone para uma ferramenta definida pelo usuário do arquivo executável da ferramenta.

Substitua esse método para fornecer seu próprio ícone de ferramenta padrão.

##  <a name="m_strarguments"></a>CUserTool::m_strArguments

Os argumentos de linha de comando para a ferramenta do usuário.

```
CString m_strArguments;
```

### <a name="remarks"></a>Comentários

Essa cadeia de caracteres é passada para a ferramenta quando você chama [CUserTool:: Invoke](#invoke) ou quando um usuário clica no comando associado a essa ferramenta.

##  <a name="m_strinitialdirectory"></a>CUserTool::m_strInitialDirectory

Especifica o diretório inicial para a ferramenta de usuário.

```
CString m_strInitialDirectory;
```

### <a name="remarks"></a>Comentários

Essa variável especifica o diretório inicial que a ferramenta executa quando você chama [CUserTool:: Invoke](#invoke) ou quando um usuário clica no comando associado a essa ferramenta.

##  <a name="m_strlabel"></a>  CUserTool::m_strLabel

O rótulo que é exibido no item de menu para a ferramenta.

```
CString m_strLabel;
```

##  <a name="serialize"></a>CUserTool:: Serialize

Para obter mais detalhes, consulte o código-fonte localizado na pasta **vc\\atlmfc\\src\\MFC** da instalação do Visual Studio.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

no *ar*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setcommand"></a>CUserTool:: SetCommand

Define o aplicativo que a ferramenta do usuário executa.

```
void SetCommand(LPCTSTR lpszCmd);
```

### <a name="parameters"></a>Parâmetros

*lpszCmd*<br/>
no Especifica o novo aplicativo a ser associado à ferramenta do usuário.

### <a name="remarks"></a>Comentários

Chame esse método para definir um novo aplicativo que a ferramenta do usuário executa. O método destrói o ícone antigo e carrega um novo ícone a partir do determinado aplicativo. Se não for possível carregar um ícone do aplicativo, ele carregará o ícone padrão para uma ferramenta de usuário chamando [CUserTool:: LoadDefaultIcon](#loaddefaulticon).

##  <a name="settoolicon"></a>  CUserTool::SetToolIcon

Carrega o ícone da ferramenta do usuário a partir do aplicativo usado pela ferramenta.

```
virtual HICON SetToolIcon();
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o ícone carregado.

### <a name="remarks"></a>Comentários

Chame esse método para carregar o ícone a ser exibido no item de menu. Esse método procura o ícone no arquivo executável usado pela ferramenta. Se não tiver um ícone padrão, o ícone fornecido por [CUserTool:: LoadDefaultIcon](#loaddefaulticon) será usado em vez disso.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CWinAppEx](../../mfc/reference/cwinappex-class.md)<br/>
[Classe CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md)
