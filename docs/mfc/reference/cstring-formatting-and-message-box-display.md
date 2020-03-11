---
title: Formatação CString e exibição da caixa de mensagem
ms.date: 11/04/2016
helpviewer_keywords:
- CString objects [MFC], formatting and message boxes
ms.assetid: d1068cf4-9cc5-4952-b9e7-d612c53cbc28
ms.openlocfilehash: ad880c5302fd2274c5d46719e912461fd7497f10
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78854039"
---
# <a name="cstring-formatting-and-message-box-display"></a>Formatação CString e exibição da caixa de mensagem

Várias funções são fornecidas para formatar e analisar `CString` objetos. Você pode usar essas funções sempre que precisar manipular objetos `CString`, mas eles são particularmente úteis para formatar Cadeias de caracteres que aparecerão no texto da caixa de mensagem.

Esse grupo de funções também inclui uma rotina global para exibir uma caixa de mensagem.

### <a name="cstring-functions"></a>Funções CString

|||
|-|-|
|[AfxExtractSubString](#afxextractsubstring)|Extrai subcadeias de caracteres separadas por um único caractere de uma determinada cadeia de caracteres de origem.|
|[AfxFormatString1](#afxformatstring1)|Substitui uma determinada cadeia de caracteres pelo formato "%1" em uma cadeia de caracteres contida na tabela de cadeia de caracteres.|
|[AfxFormatString2](#afxformatstring2)|Substitui duas cadeias de caracteres de formato "%1" e "%2" em uma cadeia de caracteres contida na tabela de cadeia de caracteres.|
|[AfxMessageBox](#afxmessagebox)|Exibe uma caixa de mensagem.|

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxextractsubstring"></a>AfxExtractSubString

Essa função global pode ser usada para extrair uma subcadeia de caracteres de uma determinada cadeia de fonte.

```
BOOL AFXAPI AfxExtractSubString (
    CString& rString,
    LPCTSTR lpszFullString,
    int iSubString,
    TCHAR chSep  = '\n');
```

### <a name="parameters"></a>parâmetros

*rString*<br/>
Referência a um objeto [CString](../../atl-mfc-shared/using-cstring.md) que receberá uma subcadeia de caracteres individual.

*lpszFullString*<br/>
Cadeia de caracteres que contém o texto completo da cadeia de caracteres a ser extraída.

*iSubString*<br/>
Índice de base zero da subcadeia de caracteres a ser extraída de *lpszFullString*.

*chSep*<br/>
Caractere separador usado para delimitar subcadeias de caracteres.

### <a name="return-value"></a>Valor retornado

TRUE se a função extraiu com êxito a subcadeia de caracteres no índice fornecido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função é útil para extrair várias subseqüências de uma cadeia de caracteres de origem quando um único caractere conhecido separa cada subcadeia de caracteres. Essa função pesquisa desde o início do parâmetro *lpszFullString* sempre que ele é chamado.

Essa função retornará FALSE se *lpszFullString* for definido como NULL ou a função atingir o final de *LpszFullString* sem encontrar *iSubString*+ 1 ocorrências do caractere separador especificado. O parâmetro *rString* não será modificado a partir de seu valor original se *lpszFullString* tiver sido definido como nulo; caso contrário, o parâmetro *rString* será definido como a cadeia de caracteres vazia se a subcadeia de caracteres não puder ser extraída para o índice especificado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#48](../../mfc/codesnippet/cpp/cstring-formatting-and-message-box-display_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxformatstring1"></a>AfxFormatString1

Substitui a cadeia de caracteres apontada por *lpsz1* para qualquer instância dos caracteres "%1" no recurso de cadeia de caracteres de modelo identificado por *nIDS*.

```
void  AfxFormatString1(
    CString& rString,
    UINT nIDS,
    LPCTSTR lpsz1);
```

### <a name="parameters"></a>parâmetros

*rString*<br/>
Uma referência a um objeto `CString` que conterá a cadeia de caracteres resultante depois que a substituição for executada.

*nIDS*<br/>
A ID de recurso da cadeia de caracteres do modelo na qual a substituição será executada.

*lpsz1*<br/>
Uma cadeia de caracteres que substituirá os caracteres de formato "%1" na cadeia de caracteres do modelo.

### <a name="remarks"></a>Comentários

A cadeia de caracteres recém-criada é armazenada em *rString*. Por exemplo, se a cadeia de caracteres na tabela de cadeia de caracteres for "arquivo %1 não encontrado" e *lpsz1* for igual a "C:\MyFile. TXT ", então *rString* conterá a cadeia de caracteres" file C:\MyFile. TXT não encontrado ". Essa função é útil para formatar Cadeias de caracteres enviadas a caixas de mensagens e outras janelas.

Se os caracteres de formato "%1" aparecerem na cadeia de caracteres mais de uma vez, várias substituições serão feitas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#25](../../mfc/codesnippet/cpp/cstring-formatting-and-message-box-display_2.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxformatstring2"></a>AfxFormatString2

Substitui a cadeia de caracteres apontada por *lpsz1* para qualquer instância dos caracteres "%1", e a cadeia de caracteres apontada por *lpsz2* para qualquer instância dos caracteres "%2", no recurso de cadeia de caracteres do modelo identificado por *nIDS*.

```
void AfxFormatString2(
    CString& rString,
    UINT nIDS,
    LPCTSTR lpsz1,
    LPCTSTR lpsz2);
```

### <a name="parameters"></a>parâmetros

*rString*<br/>
Uma referência ao `CString` que conterá a cadeia de caracteres resultante depois que a substituição for executada.

*nIDS*<br/>
A ID da tabela de cadeia de caracteres da cadeia de caracteres do modelo na qual a substituição será executada.

*lpsz1*<br/>
Uma cadeia de caracteres que substituirá os caracteres de formato "%1" na cadeia de caracteres do modelo.

*lpsz2*<br/>
Uma cadeia de caracteres que substituirá os caracteres de formato "%2" na cadeia de caracteres do modelo.

### <a name="remarks"></a>Comentários

A cadeia de caracteres recém-criada é armazenada em *rString*. Por exemplo, se a cadeia de caracteres na tabela de cadeia de caracteres for "arquivo %1 não encontrado no diretório %2", *lpsz1* apontará para "MyFile. TXT ", e *lpsz2* aponta para" C:\MYDIR ", então *rString* conterá a cadeia de caracteres" arquivo MyFile. TXT não encontrado no diretório C:\MYDIR "

Se os caracteres de formato "%1" ou "%2" aparecerem na cadeia de caracteres mais de uma vez, várias substituições serão feitas. Eles não precisam estar em ordem numérica.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#26](../../mfc/codesnippet/cpp/cstring-formatting-and-message-box-display_3.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxmessagebox"></a>AfxMessageBox

Exibe uma caixa de mensagem na tela.

```
int AfxMessageBox(
    LPCTSTR lpszText,
    UINT nType = MB_OK,
    UINT nIDHelp = 0);

int AFXAPI AfxMessageBox(
    UINT nIDPrompt,
    UINT nType = MB_OK,
    UINT nIDHelp = (UINT) -1);
```

### <a name="parameters"></a>parâmetros

*lpszText*<br/>
Aponta para um objeto `CString` ou uma cadeia de caracteres terminada em nulo que contém a mensagem a ser exibida na caixa de mensagem.

*nType*<br/>
O estilo da caixa de mensagem. Aplique qualquer um dos [estilos de caixa de mensagem](../../mfc/reference/styles-used-by-mfc.md#message-box-styles) à caixa.

*nIDHelp*<br/>
A ID de contexto da ajuda para a mensagem; 0 indica que o contexto de ajuda padrão do aplicativo será usado.

*nIDPrompt*<br/>
Uma ID exclusiva usada para fazer referência a uma cadeia de caracteres na tabela de cadeias de caracteres.

### <a name="return-value"></a>Valor retornado

Zero se não houver memória suficiente para exibir a caixa de mensagem; caso contrário, um dos seguintes valores será retornado:

- IDABORT o botão anular foi selecionado.

- IDCANCEL o botão Cancelar foi selecionado.

- IDIGNORE o botão ignorar foi selecionado.

- IDNO o botão não foi selecionado.

- IDOK o botão OK foi selecionado.

- IDRETRY o botão de repetição foi selecionado.

- IDYES o botão Sim foi selecionado.

Se uma caixa de mensagem tiver um botão Cancelar, o valor IDCANCEL será retornado se a tecla ESC for pressionada ou o botão Cancelar estiver selecionado. Se a caixa de mensagem não tiver nenhum botão Cancelar, pressionar a tecla ESC não terá nenhum efeito.

As funções [AfxFormatString1](#afxformatstring1) e [AfxFormatString2](#afxformatstring2) podem ser úteis na formatação de texto que aparece em uma caixa de mensagem.

### <a name="remarks"></a>Comentários

A primeira forma dessa função sobrecarregada exibe uma cadeia de texto apontada por *lpszText* na caixa de mensagem e usa *nIDHelp* para descrever um contexto de ajuda. O contexto de ajuda é usado para saltar para um tópico de ajuda associado quando o usuário pressiona a tecla de ajuda (normalmente F1).

A segunda forma da função usa o recurso de cadeia de caracteres com a ID *nIDPrompt* para exibir uma mensagem na caixa de mensagem. A página de ajuda associada é encontrada por meio do valor de *nIDHelp*. Se o valor padrão de *nIDHelp* for usado (-1), a ID de recurso de cadeia de caracteres, *nIDPrompt*, será usada para o contexto de ajuda. Para obter mais informações sobre como definir contextos de ajuda, consulte a [Nota técnica 28](../../mfc/tn028-context-sensitive-help-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#133](../../mfc/reference/codesnippet/cpp/cstring-formatting-and-message-box-display_4.cpp)]

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)<br/>
[Classe CStringT](../../atl-mfc-shared/reference/cstringt-class.md)
