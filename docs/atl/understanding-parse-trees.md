---
title: Registrador de ATL e árvores de análise
ms.date: 11/04/2016
helpviewer_keywords:
- parse trees
ms.assetid: 668ce2dd-a1c3-4ca0-8135-b25267cb6a85
ms.openlocfilehash: de2cea9b0e7b7c62236f708f9aa8217eaa5df51d
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168690"
---
# <a name="understanding-parse-trees"></a>Compreendendo as árvores de análise

Você pode definir uma ou mais árvores de análise no script do registrador, em que cada árvore de análise tem o seguinte formato:

> \<chave raiz> {\<expressão do registro>} +

onde:

> \<> de chave raiz:: = HKEY_CLASSES_ROOT | HKEY_CURRENT_USER | \
> &nbsp;&nbsp;&nbsp;&nbsp;HKEY_LOCAL_MACHINE | HKEY_USERS | \
> &nbsp;&nbsp;&nbsp;&nbsp;HKEY_PERFORMANCE_DATA | HKEY_DYN_DATA | \
> &nbsp;&nbsp;&nbsp;&nbsp;HKEY_CURRENT_CONFIG | HKCR | HKCU | \
> &nbsp;&nbsp;&nbsp;&nbsp;HKLM | HKU | HKPD | HKDD | HKCC

> \<expressão de registro>:: \<= adicionar chave> | \<Excluir> de chave

> \<Adicionar chave>:: = [**ForceRemove** | **NoRemove** | **Val**]\<nome da chave>\<[chave key>] [\<{Add Key>}]

> \<Excluir chave>:: = **excluir**\<nome da chave>

> \<Nome da chave>:: = **'**\<alfanumérico>+**'**

> \<> alfanumérico:: = *qualquer caractere não nulo, ou seja, ASCII 0*

> \<Valor da chave>:: \<= tipo de \<chave>nome da chave>

> \<Tipo de chave>:: = **s** | **d**

> \<Valor da chave>:: = **'**\<alfanumérico>**'**

> [!NOTE]
> `HKEY_CLASSES_ROOT`e `HKCR` são equivalentes; `HKEY_CURRENT_USER` e `HKCU` são equivalentes; e assim por diante.

Uma árvore de análise pode adicionar várias chaves e subchaves \<à chave raiz>. Ao fazer isso, ele mantém o identificador de uma subchave aberto até que o analisador tenha concluído a análise de todas as suas subchaves. Essa abordagem é mais eficiente do que operar em uma única chave por vez, como visto no exemplo a seguir:

```rgs
HKEY_CLASSES_ROOT
{
    'MyVeryOwnKey'
    {
        'HasASubKey'
        {
            'PrettyCool'
        }
    }
}
```

Aqui, o registrador inicialmente é aberto ( `HKEY_CLASSES_ROOT\MyVeryOwnKey`cria). Em seguida, ele `MyVeryOwnKey` vê que tem uma subchave. Em vez de fechar a chave `MyVeryOwnKey`para, o registrador retém o identificador e abre (cria `HasASubKey` ) usando esse identificador pai. (O registro do sistema pode ser mais lento quando não há identificador pai aberto.) Portanto, abrir `HKEY_CLASSES_ROOT\MyVeryOwnKey` e abrir `HasASubKey` o com `MyVeryOwnKey` como o pai é mais rápido do `MyVeryOwnKey`que abrir `MyVeryOwnKey`, fechar e abrir `MyVeryOwnKey\HasASubKey`.

## <a name="see-also"></a>Confira também

[Criando scripts de registrador](../atl/creating-registrar-scripts.md)
