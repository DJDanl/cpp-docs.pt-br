---
title: "Macros &lt;allocators&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
ms.reviewer: ""
ms.suite: ""
ms.tgt_pltfrm: ""
ms.topic: "article"
ms.assetid: 9cb5ee07-1ff9-4594-ae32-3c8c6efb511a
caps.latest.revision: 12
manager: "ghogen"
---
# <a name="ltallocatorsgt-macros"></a>Macros &lt;allocators&gt;
||||  
|-|-|-|  
|[ALLOCATOR_DECL](#allocator_decl)|[CACHE_CHUNKLIST](#cache_chunklist)|[CACHE_FREELIST](#cache_freelist)|  
|[CACHE_SUBALLOC](#cache_suballoc)|[SYNC_DEFAULT](#sync_default)|  
  
##  <a name="a-nameallocatordecla--allocatordecl"></a><a name="allocator_decl"></a>  ALLOCATOR_DECL  
 Produz uma classe de modelo allocator.  
  
```
#define ALLOCATOR_DECL(cache, sync, name) <alloc_template>
```  
  
### <a name="remarks"></a>Comentários  
 A macro produz uma definição de modelo `template <class Type> class name {.....}` e uma especialização `template <> class name<void> {.....}` que, em conjunto, definem uma classe de modelo allocator que usa o filtro de sincronização `sync` e um cache do tipo `cache`.  
  
 Para os compiladores que podem compilar reassociação, a definição de modelo resultante tem esta aparência:  
```  
struct rebind
   {    /* convert a name<Type> to a name<Other> */
   typedef name<Other> other;
   };  
 ```  
 Para compiladores que não podem compilar reassociação, a definição de modelo resultante tem esta aparência:  
  
```
template <class Type<class name
    : public stdext::allocators::allocator_base<Type,
    sync<stdext::allocators::rts_alloc<cache>>>
{
public:
    name() {}
    template <class Other>
    name(const name<Other>&) {}
    template <class Other>
    name& operator= (const name<Other>&)
    {
        return *this;
    }
};
```  
  
##  <a name="a-namecachechunklista--cachechunklist"></a><a name="cache_chunklist"></a>  CACHE_CHUNKLIST  
 Produz `stdext::allocators::cache_chunklist<sizeof(Type)>`.  
  
```
#define CACHE_CHUNKLIST <cache_class>
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecachefreelista--cachefreelist"></a><a name="cache_freelist"></a>  CACHE_FREELIST  
 Produz `stdext::allocators::cache_freelist<sizeof(Type), max>`.  
  
```
#define CACHE_FREELIST(max) <cache_class>
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecachesuballoca--cachesuballoc"></a><a name="cache_suballoc"></a>  CACHE_SUBALLOC  
 Produz `stdext::allocators::cache_suballoc<sizeof(Type)>`.  
  
```
#define CACHE_SUBALLOC <cache_class>
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesyncdefaulta--syncdefault"></a><a name="sync_default"></a>  SYNC_DEFAULT  
 Produz um filtro de sincronização.  
  
```
#define SYNC_DEFAULT <sync_template>
```  
  
### <a name="remarks"></a>Comentários  
 Se um compilador der suporte à compilação de aplicativos de single-threaded e multi-threaded, para aplicativos de single-threaded, a macro produzirá `stdext::allocators::sync_none`, em todos os outros casos, ela produzirá `stdext::allocators::sync_shared`.  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)




