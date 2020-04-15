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
ms.openlocfilehash: 203adeac9783da8ea49a8385dad9786865c8a225
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373213"
---
# <a name="cusertool-class"></a>Classe CUserTool

Uma ferramenta do usuário é um item de menu que executa um aplicativo externo. A guia **Ferramentas** da caixa de diálogo **Personalizar** [(CMFCToolBarsCustomizeDialog Class)](../../mfc/reference/cmfctoolbarscustomizedialog-class.md)permite que o usuário adicione ferramentas do usuário e especifique o nome, o comando, os argumentos e o diretório inicial para cada ferramenta do usuário.

## <a name="syntax"></a>Sintaxe

```
class CUserTool : public CObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CUserTool::CopyIconToClipboard](#copyicontoclipboard)||
|[CUserTool::DrawToolIcon](#drawtoolicon)|Desenha o ícone da ferramenta do usuário em um retângulo especificado.|
|[CUsertool::GetCommand](#getcommand)|Retorna uma seqüência que contém o texto do comando associado à ferramenta do usuário.|
|[CUserTool::GetCommandId](#getcommandid)|Retorna o ID de comando do item do menu da ferramenta do usuário.|
|[CUsertool::Invocar](#invoke)|Executa o comando associado à ferramenta do usuário.|
|[CUserTool::Serialize](#serialize)|Lê ou escreve este objeto de ou para um arquivo. (Substitui [cobject::Serialize](../../mfc/reference/cobject-class.md#serialize).)|
|[CUserTool::SetCommand](#setcommand)|Define o comando associado à ferramenta do usuário.|
|[CUsertool::SetToolIcon](#settoolicon)|Carrega o ícone para a ferramenta do usuário a partir do aplicativo associado à ferramenta.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CUserTool::LoadDefaultIcon](#loaddefaulticon)|Carrega o ícone padrão para uma ferramenta de usuário.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CUsertool::m_strArguments](#m_strarguments)|Os argumentos da linha de comando para a ferramenta do usuário.|
|[CUsertool::m_strInitialDirectory](#m_strinitialdirectory)|O diretório inicial da ferramenta do usuário.|
|[CUserTool::m_strLabel](#m_strlabel)|O nome da ferramenta exibido no item do menu para a ferramenta.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre como ativar as ferramentas do usuário em seu aplicativo, consulte [CUserToolsManager Class](../../mfc/reference/cusertoolsmanager-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CUserToolsManager` criar uma `m_strLabel` ferramenta a partir de um objeto, definir a variável membro e definir o aplicativo executado pela ferramenta do usuário. Este trecho de código faz parte da [amostra visual studio demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#35](../../mfc/codesnippet/cpp/cusertool-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cusertool](../../mfc/reference/cusertool-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxusertool.h

## <a name="cusertoolcopyicontoclipboard"></a><a name="copyicontoclipboard"></a>CUserTool::CopyIconToClipboard

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
BOOL CopyIconToClipboard();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cusertooldrawtoolicon"></a><a name="drawtoolicon"></a>CUserTool::DrawToolIcon

Desenha o ícone da ferramenta do usuário no centro de um retângulo especificado.

```
void DrawToolIcon(
    CDC* pDC,
    const CRect& rectImage);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*rectImage*<br/>
[em] Especifica as coordenadas da área para exibir o ícone.

## <a name="cusertoolgetcommand"></a><a name="getcommand"></a>CUsertool::GetCommand

Retorna uma seqüência que contém o texto do comando associado à ferramenta do usuário.

```
const CString& GetCommand() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência `CString` ao objeto que contém o texto do comando associado à ferramenta do usuário.

## <a name="cusertoolgetcommandid"></a><a name="getcommandid"></a>CUserTool::GetCommandId

Retorna o ID de comando da ferramenta do usuário.

```
UINT GetCommandId() const;
```

### <a name="return-value"></a>Valor retornado

O iD de comando desta ferramenta de usuário.

## <a name="cusertoolinvoke"></a><a name="invoke"></a>CUsertool::Invocar

Executa o comando associado à ferramenta do usuário.

```
virtual BOOL Invoke();
```

### <a name="return-value"></a>Valor retornado

Não zero se o comando foi executado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chama [o ShellExecute](/windows/win32/api/shellapi/nf-shellapi-shellexecutew) para executar um comando associado à ferramenta do usuário. A função falha se o comando estiver vazio ou se [o ShellExecute](/windows/win32/api/shellapi/nf-shellapi-shellexecutew) falhar.

## <a name="cusertoolloaddefaulticon"></a><a name="loaddefaulticon"></a>CUserTool::LoadDefaultIcon

Carrega o ícone padrão para uma ferramenta de usuário.

```
virtual HICON LoadDefaultIcon();
```

### <a name="return-value"></a>Valor retornado

Uma alça para o ícone carregado (HICON) ou NULL se o ícone padrão não puder ser carregado.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando não é possível carregar um ícone para uma ferramenta definida pelo usuário a partir do arquivo executável da ferramenta.

Anular este método para fornecer seu próprio ícone de ferramenta padrão.

## <a name="cusertoolm_strarguments"></a><a name="m_strarguments"></a>CUsertool::m_strArguments

Os argumentos da linha de comando para a ferramenta do usuário.

```
CString m_strArguments;
```

### <a name="remarks"></a>Comentários

Essa seqüência é passada para a ferramenta quando você chama [CUserTool::Invocar](#invoke) ou quando um usuário clica no comando associado a esta ferramenta.

## <a name="cusertoolm_strinitialdirectory"></a><a name="m_strinitialdirectory"></a>CUsertool::m_strInitialDirectory

Especifica o diretório inicial para a ferramenta do usuário.

```
CString m_strInitialDirectory;
```

### <a name="remarks"></a>Comentários

Esta variável especifica o diretório inicial que a ferramenta executa quando você chama [CUserTool:::Invocar](#invoke) ou quando um usuário clica no comando associado a esta ferramenta.

## <a name="cusertoolm_strlabel"></a><a name="m_strlabel"></a>CUserTool::m_strLabel

O rótulo exibido no item do menu para a ferramenta.

```
CString m_strLabel;
```

## <a name="cusertoolserialize"></a><a name="serialize"></a>CUserTool::Serialize

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

[em] *ar*<br/>

### <a name="remarks"></a>Comentários

## <a name="cusertoolsetcommand"></a><a name="setcommand"></a>CUserTool::SetCommand

Define o aplicativo que a ferramenta do usuário executa.

```
void SetCommand(LPCTSTR lpszCmd);
```

### <a name="parameters"></a>Parâmetros

*lpszCmd*<br/>
[em] Especifica o novo aplicativo a ser associado à ferramenta do usuário.

### <a name="remarks"></a>Comentários

Chame este método para definir um novo aplicativo que a ferramenta do usuário executa. O método destrói o ícone antigo e carrega um novo ícone do aplicativo dado. Se ele não puder carregar um ícone do aplicativo, ele carregará o ícone padrão de uma ferramenta de usuário chamando [CUserTool::LoadDefaultIcon](#loaddefaulticon).

## <a name="cusertoolsettoolicon"></a><a name="settoolicon"></a>CUsertool::SetToolIcon

Carrega o ícone para a ferramenta do usuário a partir do aplicativo que a ferramenta usa.

```
virtual HICON SetToolIcon();
```

### <a name="return-value"></a>Valor retornado

Uma alça para o ícone carregado.

### <a name="remarks"></a>Comentários

Chame este método para carregar o ícone a ser exibido no item do menu. Este método procura o ícone no arquivo executável que a ferramenta usa. Se ele não tiver um ícone padrão, o ícone fornecido por [CUserTool::LoadDefaultIcon](#loaddefaulticon) será usado em vez disso.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe Cwinappex](../../mfc/reference/cwinappex-class.md)<br/>
[Classe CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md)
