---
title: Manipulação de mensagem e destinos de comando
ms.date: 11/04/2016
f1_keywords:
- IOleCommandTarget
helpviewer_keywords:
- command targets [MFC]
- message handling [MFC], active documents
- IOleCommandTarget interface [MFC]
- command routing [MFC], command targets
ms.assetid: e45ce14c-e6b6-4262-8f3b-4e891e0ec2a3
ms.openlocfilehash: cbcbce1e476fef0d076f9c25b46b3166c1eb5935
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624343"
---
# <a name="message-handling-and-command-targets"></a>Manipulação de mensagem e destinos de comando

A interface de expedição de comando `IOleCommandTarget` define um mecanismo simples e extensível para consultar e executar comandos. Esse mecanismo é mais simples do que a automação `IDispatch` porque se baseia inteiramente em um conjunto padrão de comandos; os comandos raramente têm argumentos e nenhuma informação de tipo está envolvida (a segurança do tipo também é reduzida para argumentos de comando).

No design da interface de expedição de comando, cada comando pertence a um "grupo de comandos", que é identificado com um **GUID**. Portanto, qualquer pessoa pode definir um novo grupo e definir todos os comandos dentro desse grupo sem a necessidade de coordenar com a Microsoft ou com qualquer outro fornecedor. (Isso é essencialmente o mesmo meio de definição como uma **dispinterface** , além de **DISPIDs** na automação. Há sobreposição aqui, embora esse mecanismo de roteamento de comandos seja apenas para roteamento de comandos e não para scripts/programação em grande escala como identificadores de automação.)

`IOleCommandTarget`o lida com os seguintes cenários:

- Quando um objeto é ativado no local, somente as barras de ferramentas do objeto são exibidas normalmente e as barras de ferramentas do objeto podem ter botões para alguns dos comandos de contêiner, como **impressão**, **visualização de impressão**, **salvar**, **novo**, **zoom**e outros. (Os padrões de ativação in-loco recomendam que os objetos removam esses botões de suas barras de ferramentas ou, pelo menos, os desabilitem. Esse design permite que esses comandos sejam habilitados e ainda roteados para o manipulador correto.) Atualmente, não há nenhum mecanismo para o objeto enviar esses comandos para o contêiner.

- Quando um documento ativo é inserido em um contêiner de documento ativo (como o Office Binder), o contêiner pode precisar enviar comandos como **impressão**, **configuração de página**, **Propriedades**e outros para o documento ativo contido.

Esse roteamento simples de comando pode ser manipulado por meio de padrões de automação existentes e `IDispatch` . No entanto, a sobrecarga envolvida com o `IDispatch` é mais do que o necessário aqui, portanto, `IOleCommandTarget` fornece um meio mais simples de atingir as mesmas extremidades:

```
interface IOleCommandTarget : IUnknown
    {
    HRESULT QueryStatus(
        [in] GUID *pguidCmdGroup,
        [in] ULONG cCmds,
        [in,out][size_is(cCmds)] OLECMD *prgCmds,
        [in,out] OLECMDTEXT *pCmdText);
    HRESULT Exec(
        [in] GUID *pguidCmdGroup,
        [in] DWORD nCmdID,
        [in] DWORD nCmdExecOpt,
        [in] VARIANTARG *pvaIn,
        [in,out] VARIANTARG *pvaOut);
    }
```

O `QueryStatus` método aqui testa se um determinado conjunto de comandos, o conjunto que está sendo identificado com um **GUID**, tem suporte. Essa chamada preenche uma matriz de valores **OLECMD** (estruturas) com a lista de comandos com suporte, bem como o retorno de texto que descreve o nome de um comando e/ou informações de status. Quando o chamador quiser invocar um comando, ele poderá passar o comando (e o set **GUID**) para `Exec` juntamente com opções e argumentos, retornando um valor de retorno.

## <a name="see-also"></a>Consulte também

[Contêineres de documento ativos](active-document-containers.md)
