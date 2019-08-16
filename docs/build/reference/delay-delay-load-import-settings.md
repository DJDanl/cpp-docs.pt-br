---
title: /DELAY (configurações da importação de carga com atraso)
ms.date: 11/04/2016
f1_keywords:
- /delay
- VC.Project.VCLinkerTool.DelayNoBind
- VC.Project.VCLinkerTool.SupportUnloadOfDelayLoadedDLL
- VC.Project.VCLinkerTool.DelayUnload
helpviewer_keywords:
- delayed loading of DLLs, /DELAY option
- DELAY linker option
- /DELAY linker option
- -DELAY linker option
ms.assetid: 9334b332-cc58-4dae-b10f-a4c75972d50c
ms.openlocfilehash: ef6f5f768cf86f470d1322fa2a7bee6db794c2ef
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493004"
---
# <a name="delay-delay-load-import-settings"></a>/DELAY (configurações da importação de carga com atraso)

```
/DELAY:UNLOAD
/DELAY:NOBIND
```

## <a name="remarks"></a>Comentários

A opção/DELAY controla o [carregamento atrasado](linker-support-for-delay-loaded-dlls.md) de DLLs:

- O qualificador UNLOAD pede para a função de ajuda de carregamento atrasado dar suporte ao descarregamento explícito da DLL. A IAT (tabela de endereço de importação) é redefinida como forma original, invalidando ponteiros IAT e fazendo-os serem substituídos.

   Se você não selecionar descarregar, qualquer chamada para [FUnloadDelayLoadedDLL](explicitly-unloading-a-delay-loaded-dll.md) falhará.

- O qualificador NOBIND pede para o vinculador não incluir uma IAT associável na imagem final. O padrão é criar a IAT associável para DLLs carregadas com atraso. A imagem resultante não pode ser associada estaticamente. (As imagens com IATs associáveis podem ser associadas estaticamente antes da execução.) Consulte [/BIND](bind.md).

   Se a DLL estiver associada, a função auxiliar tentará usar as informações associadas em vez de chamar o [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) em cada uma das importações referenciadas. Se o carimbo de data/hora ou o endereço preferido não corresponder aos da DLL carregada, a função auxiliar considerará que a IAT associada está desatualizada e continuará como se a IAT associada não existisse.

   NOBIND aumenta a imagem do programa, mas pode agilizar o tempo de carregamento da DLL. Se você jamais teve a intenção associar a DLL, NOBIND evitará a geração da IAT associada.

Para especificar DLLs para atrasar a carga, use a opção [/DELAYLOAD](delayload-delay-load-import.md) .

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter informações, [consulte C++ definir compilador e propriedades de compilação no Visual Studio](../working-with-project-properties.md).

1. Expanda **Propriedades de configuração**, **vinculador**e, em seguida, selecione **avançado**.

1. Modifique a propriedade de **dll de atraso carregada** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.DelayLoadDLLs%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
