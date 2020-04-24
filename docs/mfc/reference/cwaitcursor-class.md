---
title: Classe CWaitCursor
ms.date: 11/04/2016
f1_keywords:
- CWaitCursor
- AFXWIN/CWaitCursor
- AFXWIN/CWaitCursor::CWaitCursor
- AFXWIN/CWaitCursor::Restore
helpviewer_keywords:
- CWaitCursor [MFC], CWaitCursor
- CWaitCursor [MFC], Restore
ms.assetid: 5dfae2ff-d7b6-4383-b0ad-91e0868c67b3
ms.openlocfilehash: aaa60e26d0a9bf99076f29124097b0629ce6f5d0
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754322"
---
# <a name="cwaitcursor-class"></a>Classe CWaitCursor

Fornece uma maneira de uma linha para mostrar um cursor de espera, que geralmente é exibido como uma ampulheta, enquanto você está fazendo uma operação demorada.

## <a name="syntax"></a>Sintaxe

```
class CWaitCursor
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWaitCursor::CWaitCursor](#cwaitcursor)|Constrói um `CWaitCursor` objeto e exibe o cursor de espera.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWaitCursor::Restauração](#restore)|Restaura o cursor de espera depois que ele foi alterado.|

## <a name="remarks"></a>Comentários

`CWaitCursor`não tem uma classe base.

Boas práticas de programação do Windows exigem que você exiba um cursor de espera sempre que estiver realizando uma operação que leva um tempo notável.

Para exibir um cursor de `CWaitCursor` espera, basta definir uma variável antes do código que executa a operação demorada. O construtor do objeto faz com que o cursor de espera seja exibido automaticamente.

Quando o objeto sai do escopo (no final `CWaitCursor` do bloco em que o objeto é declarado), seu destructor define o cursor para o cursor anterior. Em outras palavras, o objeto realiza a limpeza necessária automaticamente.

> [!NOTE]
> Devido ao trabalho de seus construtores e destruidores, `CWaitCursor` os objetos são sempre declarados como variáveis locais — eles nunca são declarados como variáveis globais nem são alocados com **novas**.

Se você executar uma operação que possa fazer com que o cursor seja alterado, como exibir uma caixa de mensagens ou caixa de diálogo, ligue para a função [Restaurar](#restore) membro para restaurar o cursor de espera. Não há problema `Restore` em ligar mesmo quando um cursor de espera é exibido no momento.

Outra maneira de exibir um cursor de espera é usar a combinação de [CCmdTarget::BeginWaitCursor,](../../mfc/reference/ccmdtarget-class.md#beginwaitcursor) [CCmdTarget::EndWaitCursor](../../mfc/reference/ccmdtarget-class.md#endwaitcursor)e talvez [CCmdTarget::RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor). No `CWaitCursor` entanto, é mais fácil de usar porque você não precisa definir o cursor para o cursor anterior quando você terminar com a operação demorada.

> [!NOTE]
> O MFC define e restaura o cursor usando a função virtual [CWinApp::DoWaitCursor.](../../mfc/reference/cwinapp-class.md#dowaitcursor) Você pode substituir essa função para fornecer comportamento personalizado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CWaitCursor`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#62](../../mfc/reference/codesnippet/cpp/cwaitcursor-class_1.cpp)]

## <a name="cwaitcursorcwaitcursor"></a><a name="cwaitcursor"></a>CWaitCursor::CWaitCursor

Para exibir um cursor de `CWaitCursor` espera, basta declarar um objeto antes do código que executa a operação demorada.

```
CWaitCursor();
```

### <a name="remarks"></a>Comentários

O construtor faz com que o cursor de espera seja exibido automaticamente.

Quando o objeto sai do escopo (no final `CWaitCursor` do bloco em que o objeto é declarado), seu destructor define o cursor para o cursor anterior. Em outras palavras, o objeto realiza a limpeza necessária automaticamente.

Você pode aproveitar o fato de que o destruidor é chamado no final do bloco (que pode ser antes do fim da função) para tornar o cursor de espera ativo em apenas uma parte de sua função. Esta técnica é mostrada no segundo exemplo abaixo.

> [!NOTE]
> Devido ao trabalho de seus construtores e destruidores, `CWaitCursor` os objetos são sempre declarados como variáveis locais — eles nunca são declarados como variáveis globais, nem são alocados com **novas**.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#63](../../mfc/reference/codesnippet/cpp/cwaitcursor-class_2.cpp)]

## <a name="cwaitcursorrestore"></a><a name="restore"></a>CWaitCursor::Restauração

Para restaurar o cursor de espera, ligue para esta função depois de realizar uma operação, como exibir uma caixa de mensagens ou caixa de diálogo, o que pode alterar o cursor de espera para outro cursor.

```cpp
void Restore();
```

### <a name="remarks"></a>Comentários

Não há problema `Restore` em ligar mesmo quando o cursor de espera é exibido no momento.

Se você precisar restaurar o cursor de espera enquanto `CWaitCursor` estiver em uma função diferente da em que o objeto é declarado, você pode chamar [CCmdTarget::RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#64](../../mfc/reference/codesnippet/cpp/cwaitcursor-class_3.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CCmdTarget::BeginWaitCursor](../../mfc/reference/ccmdtarget-class.md#beginwaitcursor)<br/>
[CCmdTarget::EndWaitCursor](../../mfc/reference/ccmdtarget-class.md#endwaitcursor)<br/>
[CCmdTarget::RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor)<br/>
[CWinApp::DoWaitCursor](../../mfc/reference/cwinapp-class.md#dowaitcursor)<br/>
[Como faço: alterar o cursor do mouse em um aplicativo de classe da Microsoft Foundation](https://go.microsoft.com/fwlink/p/?linkid=128044)
