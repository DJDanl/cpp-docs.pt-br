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
ms.openlocfilehash: 702cb96da13d6109c17a28e58c08a30af3f77fd4
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57302735"
---
# <a name="message-handling-and-command-targets"></a>Manipulação de mensagem e destinos de comando

A interface de expedição do comando `IOleCommandTarget` define um mecanismo simple e extensível para consultar e executar comandos. Esse mecanismo é mais simples do que pela automação `IDispatch` porque ele se baseia inteiramente em um conjunto padrão de comandos; comandos raramente têm argumentos, e nenhuma informação de tipo está envolvida (segurança de tipos é reduzida para argumentos de comando também).

O design de interface de expedição de comando, cada comando pertence a um "grupo de comando" que é identificado com uma **GUID**. Portanto, qualquer pessoa pode definir um novo grupo e definir todos os comandos dentro do grupo sem qualquer necessidade de coordenar com a Microsoft ou qualquer outro fornecedor. (Isso é essencialmente os mesmos meios de definição de como uma **dispinterface** plus **dispIDs** na automação. Há sobreposição aqui, embora esse mecanismo de roteamento do comando é apenas para o roteamento de comando e não para o script/programação em grande escala, como identificadores de automação.)

`IOleCommandTarget` lida com os seguintes cenários:

- Quando um objeto é ativado, somente as barras de ferramentas do objeto normalmente são exibidas e barras de ferramentas do objeto podem ter botões para alguns dos comandos do contêiner como in-loco **Print**, **Visualizar impressão**,  **Salve**, **New**, **Zoom**e outros. (Ativação in-loco padrões é recomendável que os objetos remover esses botões de suas barras de ferramentas ou em menos desabilitá-los. Esse design permite que esses comandos sejam habilitados e ainda é roteado para o manipulador à direita.) Atualmente, não há nenhum mecanismo para o objeto para o qual expedir esses comandos para o contêiner.

- Quando um documento ativo é inserido em um contêiner de documento ativo (por exemplo, Office Binder), o contêiner pode precisar enviar comandos tais **Print**, **Configurar página**, **propriedades**e outras para o documento ativo independente.

Esse roteamento de comando simples poderia ser tratada por meio de padrões de automação existentes e `IDispatch`. No entanto, a sobrecarga envolvida com `IDispatch` é mais do que é necessário aqui, portanto, `IOleCommandTarget` fornece um meio mais simples para atingir o mesmo terminar:

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

O `QueryStatus` método aqui testa se um determinado conjunto de comandos, o conjunto que está sendo identificado com uma **GUID**, tem suporte. Essa chamada preenche uma matriz de **OLECMD** valores (estruturas) com a lista com suporte de comandos, bem como retornar o texto que descreve o nome de um comando e/ou status de informações. Quando o chamador deseja invocar um comando, ele pode passar o comando (e o conjunto **GUID**) para `Exec` juntamente com as opções e argumentos, obter de volta um valor de retorno.

## <a name="see-also"></a>Consulte também

[Contêineres de documento ativos](../mfc/active-document-containers.md)
