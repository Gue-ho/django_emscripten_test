from django.conf.urls import patterns, url

from large_del import views

urlpatterns =patterns('',
    url(r'^$', views.index, name='index'),
    url(r'^index$', views.index, name='index'),
)

