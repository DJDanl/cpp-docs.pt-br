---
title: /INTEGRITYCHECK (exigir verificação de assinatura)
ms.date: 11/04/2016
ms.assetid: 9e738825-2c98-40cd-8ad2-5d0d9c14893e
ms.openlocfilehash: 1732c612501b66753635b272f94764975c555f75
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492843"
---
# <a name="integritycheck-require-signature-check"></a>/INTEGRITYCHECK (exigir verificação de assinatura)

Especifica que a assinatura digital da imagem binária deve ser verificada no tempo de carregamento.

```
/INTEGRITYCHECK[:NO]
```

## <a name="remarks"></a>Comentários

Por padrão, **/INTEGRITYCHECK** é off.

A opção **/INTEGRITYCHECK** define — no cabeçalho PE do arquivo dll ou do arquivo executável — um sinalizador para que o Gerenciador de memória Verifique se há uma assinatura digital para carregar a imagem no Windows. Essa opção deve ser definida para DLLs de 32 bits e 64 bits que implementam o código de modo kernel carregado por determinados recursos do Windows e é recomendada para todos os drivers de dispositivo no Windows Vista, Windows 7, Windows 8, Windows Server 2008 e Windows Server 2012. Versões do Windows anteriores ao Windows Vista ignoram esse sinalizador. Para obter mais informações, consulte [assinatura de integridade forçada de arquivos PE (executáveis portáteis)](https://social.technet.microsoft.com/wiki/contents/articles/255.forced-integrity-signing-of-portable-executable-pe-files.aspx).

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o nó **Vinculador**.

1. Selecione a página de propriedades de **linha de comando** .

1. Em **Opções adicionais**, digite `/INTEGRITYCHECK` ou `/INTEGRITYCHECK:NO`.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)<br/>
[Assinatura de integridade forçada de arquivos executáveis portáteis (PE)](https://social.technet.microsoft.com/wiki/contents/articles/255.forced-integrity-signing-of-portable-executable-pe-files.aspx)<br/>
[Requisitos de assinatura de código no modo kernel](/windows-hardware/drivers/install/kernel-mode-code-signing-requirements--windows-vista-and-later-)<br/>
[AppInit DLLs e inicialização segura](/windows/win32/dlls/secure-boot-and-appinit-dlls)
