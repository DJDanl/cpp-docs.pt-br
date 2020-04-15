---
title: Formatação CString e exibição da caixa de mensagem
ms.date: 11/04/2016
helpviewer_keywords:
- CString objects [MFC], formatting and message boxes
ms.assetid: d1068cf4-9cc5-4952-b9e7-d612c53cbc28
ms.openlocfilehash: d30d26ecf0e72ee33affe3df5b88c438ff83bb6b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366000"
---
# <a name="cstring-formatting-and-message-box-display"></a>Formatação CString e exibição da caixa de mensagem

Uma série de funções são fornecidas `CString` para formatar e analisar objetos. Você pode usar essas funções `CString` sempre que tiver que manipular objetos, mas eles são particularmente úteis para formatar strings que aparecerão no texto da caixa de mensagens.

Este grupo de funções também inclui uma rotina global para exibir uma caixa de mensagens.

### <a name="cstring-functions"></a>Funções cstring

|||
|-|-|
|[AfxExtractSubString](#afxextractsubstring)|Extrai substrings separadas por um único caractere de uma determinada seqüência de origem.|
|[AfxFormatString1](#afxformatstring1)|Substitui uma determinada seqüência de caracteres para os caracteres de formato "%1" em uma seqüência contida na tabela de strings.|
|[AfxFormatString2](#afxformatstring2)|Substitui duas strings para os caracteres de formato "%1" e "%2" em uma seqüência contida na tabela de strings.|
|[AfxMessageBox](#afxmessagebox)|Exibe uma caixa de mensagem.|

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxextractsubstring"></a><a name="afxextractsubstring"></a>AfxExtractSubString

Esta função global pode ser usada para extrair uma substring de uma determinada seqüência de origem.

```
BOOL AFXAPI AfxExtractSubString (
    CString& rString,
    LPCTSTR lpszFullString,
    int iSubString,
    TCHAR chSep  = '\n');
```

### <a name="parameters"></a>Parâmetros

*rString*<br/>
Referência a um objeto [CString](../../atl-mfc-shared/using-cstring.md) que receberá uma substringindividual.

*Lpszfullstring*<br/>
String contendo o texto completo da seqüência para extrair.

*iSubString*<br/>
Índice baseado em zero da substring para extrair de *lpszFullString*.

*chSep*<br/>
Caractere separador usado para delimitar substrings.

### <a name="return-value"></a>Valor retornado

TRUE se a função extraísse com sucesso a substring no índice fornecido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esta função é útil para extrair várias substrings de uma seqüência de caracteres de origem quando um caractere único conhecido separa cada substring. Esta função é pesquisada desde o início do parâmetro *lpszFullString* cada vez que é chamada.

Esta função retornará FALSE se *lpszFullString* estiver definido como NULL ou a função atingir o final do *lpszFullString* sem encontrar *iSubString*+1 ocorrências do caractere separador especificado. O parâmetro *rString* não será modificado do seu valor original se *lpszFullString* foi definido como NULL; caso contrário, o parâmetro *rString* é definido para a seqüência vazia se a substring não puder ser extraída para o índice especificado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#48](../../mfc/codesnippet/cpp/cstring-formatting-and-message-box-display_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxformatstring1"></a><a name="afxformatstring1"></a>AfxFormatString1

Substitui a string apontada por *lpsz1* para quaisquer instâncias dos caracteres "%1" no recurso de string modelo identificado por *nIDS*.

```
void  AfxFormatString1(
    CString& rString,
    UINT nIDS,
    LPCTSTR lpsz1);
```

### <a name="parameters"></a>Parâmetros

*rString*<br/>
Uma referência `CString` a um objeto que conterá a seqüência resultante após a substituição é realizada.

*Nids*<br/>
O ID de recurso da seqüência de modelo selante no qual a substituição será realizada.

*lpsz1*<br/>
Uma seqüência de caracteres que substituirá os caracteres de formato "%1" na seqüência de modelos.

### <a name="remarks"></a>Comentários

A seqüência recém-formada é armazenada em *rString*. Por exemplo, se a seqüência na tabela de strings for "Arquivo %1 não encontrado", e *lpsz1* for igual a "C:\MYFILE. TXT", então *rString* conterá a string "Arquivo C:\MYFILE. TXT não encontrado". Esta função é útil para formatar strings enviadas para caixas de mensagens e outras janelas.

Se os caracteres de formato "%1" aparecerem na seqüência mais de uma vez, várias substituições serão feitas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#25](../../mfc/codesnippet/cpp/cstring-formatting-and-message-box-display_2.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxformatstring2"></a><a name="afxformatstring2"></a>AfxFormatString2

Substitui a string apontada por *lpsz1* para quaisquer instâncias dos caracteres "%1", e a string apontada por *lpsz2* para quaisquer instâncias dos caracteres "%2", no recurso de string modelo identificado por *nIDS*.

```
void AfxFormatString2(
    CString& rString,
    UINT nIDS,
    LPCTSTR lpsz1,
    LPCTSTR lpsz2);
```

### <a name="parameters"></a>Parâmetros

*rString*<br/>
Uma referência `CString` ao que conterá a seqüência resultante após a substituição é realizada.

*Nids*<br/>
O ID da tabela de strings da seqüência de modelo selante na qual a substituição será realizada.

*lpsz1*<br/>
Uma seqüência de caracteres que substituirá os caracteres de formato "%1" na seqüência de modelos.

*lpsz2*<br/>
Uma seqüência de caracteres que substituirá os caracteres de formato "%2" na seqüência de modelos.

### <a name="remarks"></a>Comentários

A seqüência recém-formada é armazenada em *rString*. Por exemplo, se a string na tabela de strings for "Arquivo %1 não encontrado no diretório %2", *lpsz1* aponta para "MYFILE. TXT", e *lpsz2* aponta para "C:\MYDIR", então *rString* conterá a string "File MYFILE. TXT não encontrado no diretório C:\MYDIR"

Se os caracteres de formato "%1" ou "%2" aparecerem na seqüência mais de uma vez, várias substituições serão feitas. Eles não têm que estar em ordem numérica.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#26](../../mfc/codesnippet/cpp/cstring-formatting-and-message-box-display_3.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxmessagebox"></a><a name="afxmessagebox"></a>Afxmessagebox

Exibe uma caixa de mensagens na tela.

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

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Aponta para `CString` uma seqüência de objeto ou nulo com término contendo a mensagem a ser exibida na caixa de mensagens.

*nType*<br/>
O estilo da caixa de mensagens. Aplique qualquer um dos [estilos de caixa de mensagem](../../mfc/reference/styles-used-by-mfc.md#message-box-styles) à caixa.

*Nidhelp*<br/>
O ID do contexto de ajuda para a mensagem; 0 indica que o contexto de ajuda padrão do aplicativo será usado.

*nIDPrompt*<br/>
Um ID único usado para referenciar uma string na tabela de strings.

### <a name="return-value"></a>Valor retornado

Zero se não houver memória suficiente para exibir a caixa de mensagens; caso contrário, um dos seguintes valores é devolvido:

- IDABORT O botão Abort foi selecionado.

- IDCANCEL O botão Cancelar foi selecionado.

- IDIGNORE O botão Ignorar foi selecionado.

- IDNO O botão No foi selecionado.

- IDOK O botão OK foi selecionado.

- IDRETRY O botão Retry foi selecionado.

- IDYES O botão Yes foi selecionado.

Se uma caixa de mensagem tiver um botão Cancelar, o valor IDCANCEL será retornado se a tecla ESC estiver pressionada ou o botão Cancelar estiver selecionado. Se a caixa de mensagens não tiver botão Cancelar, pressionar a tecla ESC não tem efeito.

As funções [AfxFormatString1](#afxformatstring1) e [AfxFormatString2](#afxformatstring2) podem ser úteis na formatação de texto que aparece em uma caixa de mensagem.

### <a name="remarks"></a>Comentários

A primeira forma desta função sobrecarregada exibe uma seqüência de texto apontada por *lpszText* na caixa de mensagens e usa *nIDHelp* para descrever um contexto de Ajuda. O contexto de Ajuda é usado para saltar para um tópico de Ajuda associado quando o usuário pressiona a tecla Ajuda (tipicamente F1).

A segunda forma da função usa o recurso string com o ID *nIDPrompt* para exibir uma mensagem na caixa de mensagens. A página de ajuda associada é encontrada através do valor do *nIDHelp*. Se o valor padrão do *nIDHelp* for usado (-1), o ID de recurso de string, *nIDPrompt,* será usado para o contexto de Ajuda. Para obter mais informações sobre como definir contextos de ajuda, consulte [Nota Técnica 28](../../mfc/tn028-context-sensitive-help-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#133](../../mfc/reference/codesnippet/cpp/cstring-formatting-and-message-box-display_4.cpp)]

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)<br/>
[Classe Cstringt](../../atl-mfc-shared/reference/cstringt-class.md)
